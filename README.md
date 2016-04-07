# ![SPICE Logo](raw.github.com/LukasMuellerILT/SPICE/tree/master/SPICE_Logos/SPICE_064.png) SPI_DeviceSimulator

SPI_DeviceSimulator is an implemented SiLA ServiceProvider based on [SPICE](https://github.com/LukasMuellerILT/SPICE).

## Idea
* Idea is to have a SiLA ServiceProvider available which implements as much as possible of the existing standard.
This enables to test available PMSs (Process Management Systems) and see how they react on diffrent situations and
how proper they work with the diffrent data-types.
* It also gives an idea how SPICE can be used.

## Provided Functionality
* A series of commands with parameter in diffrent data-types. The commands always return the parameter-value in their response-data.
* Two commands which are possible to run parallel to themself and each other.
* Two commands which aren't able to run parallel.
* A command which throws an error. The error-type can be set over the parameter (as example: recoverable / not recoverable)
* WSDiscovery (Type: "SiLADevice", no Scope)

## SiLAVersion
SPI_DeviceSimulator v1.0: based on SPICE 1.0.x, implements SiLA DCIS 1.3.08 specification

## License
SPI_DeviceSimulator is provided under the Boost Software License. SPI_DeviceSimulator is not and has no intention to be part of the Boost
libraries. It just uses this very open license that encourages both commercial and non-commercial use.

> Boost Software License - Version 1.0 - August 17th, 2003
>
> Permission is hereby granted, free of charge, to any person or organization
> obtaining a copy of the software and accompanying documentation covered by
> this license (the "Software") to use, reproduce, display, distribute,
> execute, and transmit the Software, and to prepare derivative works of the
> Software, and to permit third-parties to whom the Software is furnished to
> do so, all subject to the following:
>
> The copyright notices in the Software and this entire statement, including
> the above license grant, this restriction and the following disclaimer,
> must be included in all copies of the Software, in whole or in part, and
> all derivative works of the Software, unless such copies or derivative
> works are solely in the form of machine-executable object code generated by
> a source language processor.
>
> THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
> IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
> FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
> SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
> FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
> ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
> DEALINGS IN THE SOFTWARE.

Source: http://www.boost.org/users/license.html

