# ragemp-conf-override

Intercepts file open calls to `"conf.json"` and redirects to a replacement file specified via the environment variable `CONF_JSON_PATH`.

## Building

To build the shared library, run:

```bash
make
```

## Usage

```
CONF_JSON_PATH=/path/to/your/config.json LD_PRELOAD=./ragemp-conf-override.so ./ragemp-server
```