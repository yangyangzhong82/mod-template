# Changelog

All notable changes to this project will be documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.0.0/),
and this project adheres to [Semantic Versioning](https://semver.org/spec/v2.0.0.html).

## [Unreleased]

### Added

- Add `EventRegistrar` with a player join event example.
- Add configurable join behaviors in `Config`:
  - `exampleJoinMessageEnable`
  - `exampleJoinLogEnable`
- Add new i18n keys for lifecycle and event logs/messages.
- Add `scripts/init-template.ps1` to initialize template placeholders.

### Changed

- Improve `README` with setup, structure, and extension workflow.
- Introduce `src/mod/Global.h` and keep `src/mod/Gloabl.h` as a compatibility include.
- Fix `ConfigManager` logger shadowing warnings and namespace comment.
- Normalize `Config` header include usage (`Config.h`).
- Make example behavior opt-in by default for template neutrality.
