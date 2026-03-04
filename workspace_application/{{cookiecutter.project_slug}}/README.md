# {{cookiecutter.application}}

{%- if cookiecutter.secure_app|lower == "true" %}
> [!WARNING]
>
> Depending on which resistor you’ve fitted on your Zest Security Secure Element, you must update `app.overlay` accordingly:
>
> - R3 (Default): `ZEST_SECURITY_SECUREELEMENT(1);`
> - R4: `ZEST_SECURITY_SECUREELEMENT(1, DIO6);`
> - R5: `ZEST_SECURITY_SECUREELEMENT(1, DIO11);`
{%- endif %}
