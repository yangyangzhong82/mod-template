# LeviLamina Mod Template

Reusable LeviLamina C++ template for mod authors.

What this template provides:

- Config bootstrap and default value fallback
- I18n loader (`lang/*.json`)
- Event registration skeleton
- Standard `load/enable/disable` lifecycle

## Quick Start

1. Create a repository from this template and clone it.
2. Initialize placeholders with the helper script:

```powershell
powershell -ExecutionPolicy Bypass -File .\scripts\init-template.ps1 `
  -ModName "my-awesome-mod" `
  -Tooth "github.com/your-org/my-awesome-mod"
```

3. Update LeviLamina version in `xmake.lua` if needed.
4. Build:

```powershell
xmake f -y -p windows -a x64 -m release --target_type=server
xmake
```

Build output is generated under `bin/`.

`init-template.ps1` options:

- `-Namespace`: custom C++ namespace (default from `-ModName`)
- `-DisplayName`: mod display name (default from `-ModName`)
- `-Description`: `tooth.json` description text
- `-DryRun`: preview replacements without writing files

## Project Structure

- `src/mod/Entry.cpp`: lifecycle entrypoint
- `src/Event/EventRegistrar.cpp`: event register/unregister example
- `src/Config/Config.h`: config schema
- `src/Config/ConfigManager.cpp`: config load/save
- `src/I18n/I18n.cpp`: i18n load/lookup
- `lang/zh_CN.json` / `lang/en_US.json`: translations

## Default Config

On first run, `config/config.json` is auto-generated.
When new top-level fields are added in code, missing keys are appended automatically while preserving existing comments and current key order.

- `version`: config version
- `logLevel`: logger level
- `language`: active locale, e.g. `en_US`, `zh_CN`
- `exampleJoinMessageEnable`: example join message switch (default `false`)
- `exampleJoinLogEnable`: example join log switch (default `false`)

## Extend This Template

1. Add your listeners under `src/Event`.
2. Keep registration centralized in `EventRegistrar`.
3. Add config fields in `src/Config/Config.h`.
4. Add translation keys in `lang/*.json`.
5. Wire your modules in `Entry::enable()`.

## References

- LeviLamina docs: https://lamina.levimc.org/developer_guides/tutorials/create_your_first_mod/

## License

CC0-1.0 © LeviMC (LiteLDev)
