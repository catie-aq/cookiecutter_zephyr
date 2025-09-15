# {{cookiecutter.application}}

{%- if cookiecutter.secure_app|lower == "true" %}
> [!WARNING]
>
> Depending on which resistor you’ve fitted on your Zest Security Secure Element, you must update `app.overlay` accordingly:
>
> - R3 (Default): `<&sixtron_connector DIO1 GPIO_ACTIVE_HIGH>;`
> - R4: `<&sixtron_connector DIO6 GPIO_ACTIVE_HIGH>;`
> - R5: `<&sixtron_connector DIO11 GPIO_ACTIVE_HIGH>;`
{%- endif %}
