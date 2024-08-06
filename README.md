# Anh's Workflow Test

No, this won't be on the real Geode workflow file. Very specific use case.

> [!WARNING]  
> For the changelog and version appender feature to work, you MUST go to `Settings` > `Actions` > `General`, find `Workflow Permissions` and check `Read and write permissions`. The ability to use your own GitHub authentication token will be available in the future.

Features:
- [x] Conditional activation
  - [ ] Additional check for special cases (e.g. "very special update")
- [x] Automatic changelog appender
  - [ ] Also do the same to the release page (Could be done by extracting the mod, will definitely have to try out)
- [x] Automatic mod version bumper
  - [ ] Check to prevent the workflow from continuing upon detecting duplicate version
- [x] Automatic release creator
  - [ ] Option to mark the release as draft instead
  - [ ] Option to mark it as pre-release
  - [x] Automatically update tags

Most importantly:
- [ ] Make this portable, so it can be used with the Actions Marketplace
  - [ ] Also make configurable
