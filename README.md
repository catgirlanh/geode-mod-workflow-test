# Anh's Workflow Test

> [!WARNING]  
> If you're using the changelog and version appender feature with a GitHub-provided token, you **MUST** go to `Settings` > `Actions` > `General`, find `Workflow Permissions` and check `Read and write permissions`. The ability to use your own GitHub authentication token will be available in the future.

> [!NOTE]
> - This workflow currently is in beta and is being extensively tested and worked on. Use this at your own risk.
> - Your mod **must have been on the index beforehand** for the automatic updating to work.

> [!IMPORTANT]
> A personal access token (PAT) is **required** to automatically publish your mod to the Geode index. See [here](https://docs.github.com/en/authentication/keeping-your-account-and-data-secure/managing-your-personal-access-tokens) on how to create your PATs, and [here](https://docs.github.com/en/actions/security-for-github-actions/security-guides/using-secrets-in-github-actions) on how to set the repository secret. For the full instructions, see [the setup guide](https://github.com/catgirlanh/geode-mod-workflow-test/wiki/Setup-Guide).

## Features
- [x] Conditional activation
  - [x] Additional check for special cases (e.g. "very special update")
- [x] Automatic changelog appender
  - [x] Also do the same to the release page
  - [ ] Omit adding changelog entirely if extended commit description is left blank
- [x] Automatic mod version bumper
  - [ ] Check to prevent the workflow from continuing upon detecting duplicate version
- [x] Automatic release creator
  - [ ] Option to mark the release as draft instead
  - [ ] Option to mark it as pre-release
  - [x] Automatically update tags
- [ ] Automatically submit updates to the index (i feel bad for repo staffs but whatever)

## Known Bugs
### When a line is checked, it means the bug has been fixed.
- [ ] There is currently no way to continue anyway when a single platform build fails
- [ ] Secondary version check is broken and always returns "pass"
- [ ] Workflow fails when there's no changelog.md file present

## Misc.
### (low priority, as I'm not done polishing things up)
- [ ] Make this portable, so it can be used with the Actions Marketplace
  - [ ] Also make configurable
