# Level Zero Spec Proposals

This folder contains proposals linked to from GitHub Issues.

## Process

1. File a Feature Request \(**FR**\) Issue on GitHub.
2. Use [the proposals template](templates/LevelZeroSpecProposalTemplate.md) to create a new proposal document under a new folder named with the Issue number from \(1\).
    - Ex:
        ```bash
        mkdir /path/to/l0-spec/proposals/1234
        cp /path/to/l0-spec/proposals/templates/LevelZeroSpecProposalTemplate.md \
           /path/to/l0-spec/proposals/1234/ExampleFeature-1234.md
       ```
3. Iterate on the proposal.
4. Once the proposal is satisfactory, make a pull request against the `master` branch of the upstream repo.
    - This will enqueue the feature request for discussion in the **Proposals Review Forum**.
    - This will also inform the maintainers about the readiness of the feature request and they will:
        1. Update the Issue from \(1\) to link to the PR, and
        2. Update the Issue label \(from *FR-New Request* to *FR-Under Review*\).
5. Participate in the **Proposal Review Forum**.
    - The issuer of the proposal PR will be informed when the proposal is on the agenda for discussion. Some proposals may be discussed asynchronously via Teams, or directly in the PR.
    - A representative of the proposal should participate in the Proposal Review. Be prepared to advocate for the proposal and answer any questions/comments/concerns.
6. If ratified by the **Board of Promoters**
    - The Issue label will be updated to *FR-Ratified*.
    - The proposal PR will be merged.
    - The Issue will be updated to reference the proposal document.
7. Once ratified,
    - The original author\(s\) of the proposal own translating the proposal into "spec language" \(`.yml` and `.rst` files\), and making a feature PR for the Issue with a description that includes the text:
        ```text
        Resolves: intel-innersource/libraries.compute.oneapi.level-zero.spec#<issue number>
        ```
    - The feature PR is reviewed. The original author is responsible for addressing feedback comments from reviewers and for keeping the PR updated/current.
    - Once approved, a maintainer will migrate the Issue and the feature PR to the public repo, where the community will have an opportunity to review and comment on either and/or both the \(public\) GitHub Issue itself and the corresponding \(public\) PR. The innersource GitHub Issue and PR will be marked closed.
8. Once the public PR is approved, it will be merged into the next release-candidate.

## Example

Say we want to create a new feature request. Here's the flow, assuming we have forked the repo and have ensured our fork and local workspace are current:

1. First, we file a new Feature Request Issue. Great! GitHub assigned it Issue number **1234**.
    - Let's go ahead here and create a local working branch, or topic branch for our work.
2. Next, we create a folder under proposals, named **1234**
    - Then, we copy the proposals template markdown file into our new folder and give it a meaningful name. We'll also be sure to append "-1234" just before the filename extension \(".md"\), Ex: `ExampleFeatureName-1234.md`. We also happen to know we're going to want to include some illustrations in our proposal, so we'll create a sub-directory under `1234` called `assets` to store our images.

        At this point, our directory structure looks like this:
        ```text
        [level-zero-spec] \
            |
            |-> [proposals] \
            |      |
            |      |-> [1234] \
            |      |    |
            |      |    |-> [assets] \
            |      |    |      |
            |      |    |      |-> ExampleImage.png
            |      |    |      |---
            |      |    |-> ExampleFeatureName-1234.md
            |      |    |---
            |      |-> [templates]
            |      |---
            |---
        ```
3. With the structure set up for the document, we work with our colleagues and iterate on the proposal itself, making commits to our local workspace, pushing to our fork as necessary, etc...
4. With the iteration complete and everyone involved so far happy with the proposal, even if it is just one contributor, we are ready to push the topic branch to our upstream and make a PR against the maintainer's `master` branch.
5. Maintainer let us know our proposal will be discussed in the next **Proposal Review Forum**. Great! Making progress! We go to / call into the forum and champion our proposal. Everyone loves it, we did a great job preparing.
6. The **Board of Promoters** ratifies our proposal. Sweet!
7. Now that the hard work is done, we \(*"we" being the authors of the proposal*\) translate our proposal to "spec language". We write up the `.yml` \(spec\) and `.rst` \(programming guide\) changes and submit a PR, referencing the Issue in the commit message, of course.
    - The review highlights that some additional adjustments are required. We patch those up and the PR is approved. Awesome!

Because this is in the internal repo, one of the maintainers migrates our Issue to the public repo along with a formatted patch PR. The public loves our proposal, or at least doesn't complain, and the maintainers approve and merge it into the release-candidate. The proposal is complete and the feature is slated for the next spec release! High-five!
