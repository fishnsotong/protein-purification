## protein-purification module
A simple pneumatically controlled device that automates column
chromatography protocols commonly used in [protein purification][info] and
enrichment.

## project status
Initial prototype is functional and very promising. The project is still in
early development, and code refactoring to promote future expandability and
portability is still required. 

## equipment
_to be added_

## future work
- some type of sensor (LDR?) to halt the machine once elution is complete
- couple the setup to an absorbance detector for inline characterization
- enable processing of elution gradients

## directory structure

stable - current working version of 'src' - src code is experimental
include - project header files 
lib - project specific (private) libraries 
src - project source files 
platformio.ini - project configuration file

## build instructions
Download the latest version of [PlatformIO][platformio] or the Arduino IDE

`pio run` - process/build project from the current directory 
`pio run --target upload` or
`pio run -t upload` - upload firmware to a target 
`pio run --target clean` - clean project (remove compiled files) 
`pio run --help` - additional information

[info]: https://www.labome.com/method/Protein-Purification.html
[platformio]: https://platformio.org/
