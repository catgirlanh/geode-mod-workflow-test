# Anh's Workflow Test

> [!WARNING]  
> For the changelog and version appender feature to work, you MUST go to `Settings` > `Actions` > `General`, find `Workflow Permissions` and check `Read and write permissions`. The ability to use your own GitHub authentication token will be available in the future.

> [!IMPORTANT]
> This workflow currently is in beta and is being extensively tested and worked on. Use this at your own risk.

## Features
- [x] Conditional activation
  - [x] Additional check for special cases (e.g. "very special update")
- [x] Automatic changelog appender
  - [ ] Also do the same to the release page (Could be done by extracting the mod, will definitely have to try out)
  - [ ] Omit adding changelog entirely if extended commit description is left blank
- [x] Automatic mod version bumper
  - [ ] Check to prevent the workflow from continuing upon detecting duplicate version
- [x] Automatic release creator
  - [ ] Option to mark the release as draft instead
  - [ ] Option to mark it as pre-release
  - [x] Automatically update tags

## Known Bugs
### When a line is checked, it means the bug has been fixed.
- [ ] There is currently no way to continue anyway when a single platform build fails
Most importantly:
(low priority, as I'm not done polishing things up)
- [ ] Make this portable, so it can be used with the Actions Marketplace
  - [ ] Also make configurable
