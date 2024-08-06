# Anh's Workflow Test

No, this won't be on the real Geode workflow file. Very specific use case.
Features:
- [x] Conditional activation
  - [ ] Additional check for special cases (e.g. "very special update")
- [x] Automatic changelog appender
  - [ ] Also do the same to the release page (This is very hard, as variables are isolated between jobs)
- [x] Automatic mod version bumper
  - [ ] Check to prevent the workflow from continuing upon detecting duplicate version
- [x] Automatic release creator
  - [ ] Option to mark the release as draft instead
  - [ ] Option to mark it as pre-release

Most importantly:
- [ ] Make this portable, so it can be used with the Actions Marketplace
