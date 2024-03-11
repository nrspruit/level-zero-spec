# \<TITLE\>

## Metadata

### Component

\<COMPONENT\>

> Template Comment 1.0
> --------------------
> Possible Components include:
>    - Core
>    - Tools
>    - Sysman

### Classification

\<CLASSIFICATION\>

> Template Comment 1.1
> --------------------
> Possible Classifications include:
>    - API
>    - Extension
>    - Experimental Extension
>    - ~~Vendor Extension~~ *# Vendor extensions don't exist \(yet\)*
>    - ~~Driver Private Extension~~ *# Driver private extensions should be tracked in JIRA*

### Authors

- \[First Name\] \[Last Name\] \<email.address@domain\>

## Summary

\<TEXT\>

> Template Comment 2.0
> --------------------
> The Summary section should contain a brief executive summary of this proposal.
>
> Template Comment 2.1
> --------------------
> Sometimes a picture is worth a thousand words. If images are helpful to the proposal, create an 'assets' folder at the same level as the proposal markdown file and reference images as `![Alt Text](assets/ExampleImage.png)`.
>
> ```text
> level-zero-spec
>  |
>  |-> proposals
>  |      |
>  |      |-> 1234
>  |      |    |
>  |      |    |-> assets
>  |      |    |      |
>  |      |    |      |-> ExampleImage.png
>  |      |    |      |---
>  |      |    |-> ExampleProposal-1234.md
>  |      |    |---
>  |      |---
>  ---
> ```

## Motivation

> Template Comment 3.0
> --------------------
> The Motivation section is where the problem statement resides. Describe the problem this proposal aims to resolve.

## Description

\<TEXT\>

> Template Comment 4.0
> --------------------
> The Description section is the heart of the proposal. It should include a detailed description of what is being proposed, including narrative text and possibly pseudo-code demonstrating expected usage. Narrative text should cover use-cases, performance benefits, etc., and pseudo-code should be clear and concise \(complete with comments\).

## Dependencies

\<TEXT\>

> Template Comment 5.0
> --------------------
> The Dependencies section should list any dependencies required for this proposal, such as base-line spec revision number, extensions, etc.

## Details

\<TEXT\>

---

> Template Comment 6.0
> --------------------
> The Details section gets into the mechanics of the proposal. Describe what APIs and related types, data structures, flows, etc... are being introduced, and how they are expected to be used.
> 
> For the description of function parameters, structure fields, etc... it is helpful to color code the element properties. Typically, the spec will have something like:
> 
> ```
> [ in ][optional][range(0, count)] description
>   (1)     (2)         (3)            (4)
> ```
>
> Where,
> 
>    1. = the direction of the element \(ex: '*in*', '*in, out*', '*out*'\)
>    2. = whether the element is optional \(ex: present if yes, not present if no\)
>    3. = expected range of the element \(ex: also present if yes, not present if no\)
>
> While not required, it is nice to add some color to the proposal. As illustrated in the following examples this template uses the following color scheme:
>
>    1. = `\[ ${\textsf{\color{orange}<direction>}}$ \] <description>`
>    2. = `\[ ${\textsf{\color{lightblue}optional}}$ \] <description>`
>    3. = `\[ ${\textsf{\color{green}range(0, <count>)}}$ \] <description>`
>
> Which renders as (for example):
> 
>    1. \[ ${\textsf{\color{orange}in}}$ \] *description*
>    2. \[ ${\textsf{\color{lightblue}optional}}$ \] *description*
>    3. \[ ${\textsf{\color{green}range(0, count)}}$ \] *description*

### New Object Types

#### ze_example_exp_handle_t

- *example description for the example handle type*

---

### New Entry Points

#### zeExampleFunctionExp

```cpp
ze_result_t zeExampleFunctionExp(
    ze_example_exp_handle_t                hExample,
    ze_example_structure_exp_properties_t* pProperties
);
```

| Parameter   | Description |
| :---------- | :----------------------------------------                                 |
| hExample    | \[ ${\textsf{\color{orange}in}}$ \] handle of the example                 |
| pProperties | \[ ${\textsf{\color{orange}in, out}}$ \] *example properties description* |

---

### New Enums

#### ze_example_enum_exp_flags_t

```cpp
typedef uint32_t ze_example_enum_exp_flags_t;
typedef enum _ze_example_enum_exp_flag_t {
    ZE_EXAMPLE_ENUM_EXP_FLAG_EXAMPLE_A = ZE_BIT(0),
    ZE_EXAMPLE_ENUM_EXP_FLAG_EXAMPLE_B = ZE_BIT(1),

    ZE_EXAMPLE_ENUM_EXP_FLAG_FORCE_UINT32 = 0x7fffffff

} ze_example_enum_exp_flag_t;
```

| Flag        | Description                               |
| :---------- | :---------------------------------------- |
| EXAMPLE_A   | *example flag A description.*             |
| EXAMPLE_B   | *example flag B description.*             |

---

### New Structures

#### ze_example_structure_exp_properties_t

```cpp
typedef struct _ze_example_structure_exp_properties_t {
    ze_structure_type_t         stype; // derived from ze_base_properties_t
    const void*                 pNext; // derived from ze_base_properties_t

    ze_example_enum_exp_flags_t flags;
 
} ze_example_structure_exp_properties_t;
```

| Field       | Description                                                         |
| :---------- | :----------------------------------------                           |
| **stype**   | \[ ${\textsf{\color{orange}in}}$ \] type of this structure          |
| **pNext**   | \[ ${\textsf{\color{orange}in, out}}$ \]\[ ${\textsf{\color{lightblue}optional}}$ \] must be nul or a pointer to an extension specific structure (i.e. contains `stype` and `pNext`). |
| **flags**   | \[ ${\textsf{\color{orange}out}}$ \] example description for flags. |

---

### Example Usage

```cpp
ze_example_structure_exp_properties_t exampleProperties = {
    ZE_STRUCTURE_TYPE_EXAMPLE_EXP_PROPERTIES
};

// Get the example properties
zeDeviceExampleFunctionExp(hExample, &exampleProperties);

// Check for EXAMPLE_B
if (0 != (exampleProperties.flags & ZE_EXAMPLE_ENUM_EXP_FLAG_EXAMPLE_B)) {
    // EXAMPLE_B supported
} else {
    // EXAMPLE_B not supported
}
```
