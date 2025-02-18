# Overview

This sample application provides an example usage of the {{cookiecutter.vendor}} {{cookiecutter.reference}} {{cookiecutter.sensor_type}}.

> [!NOTE]
>
> Optional overview notes

## Requirements

- List of required elements

> [!NOTE]
>
> Optional requirement notes

## References

- [{{cookiecutter.reference}} Component]().
- [{{cookiecutter.reference}} Datasheet]().

> [!NOTE]
>
> Optional reference notes

## Building and Running

```shell
cd {{cookiecutter.project_slug}}
west build -p always -b <BOARD> samples/ -- -D DTC_OVERLAY_FILE=sixtron_bus.overlay
west flash
```

> [!NOTE]
>
> Optional building notes

## Sample Output

```shell
*** Booting Zephyr OS build v3.7.0 ***

# Fill with correct expected output

<repeats endlessly>
```
