The development of the TocoSat software follows the methodology discussed below. It can be viewed that a typical standard approach can be taken to a new specific mission and tailored to meet the exact mission requirements, however not every aspect of the software needs to be unique. The overall skeleton of the software structure and development cycle can be similar between projects and mission.

This approach will be applied to the overall final `EBB` software. In the `\test_code` directory is small projects used for development and understanding of these interfaces and behaviours of the spacecraft. This approach assumes there is known working code and examples for each module and interface, just yet to be combined or tailored for the specific mission.

This idea that a generic recipe can be applied is tested in this project. The overall building blocks of a spacecraft's software are detailed as:

- States
	- The expected states of the spacecraft should be defined and some skeletal code structure to execute certain aspects of the operations as required. 
	- This should be the main building block for the rest of the software development. 
- Internal Time
	- Time references of the spacecraft need to be decided. The use of the internal time should be used for timing between executions of code or time intervals. Using an external time reference, GPS, RTC or RF link etc. can also be implemented. If so this should be the next priority.
- Initialising Interfaces
	- Of all the interfaces the spacecraft should initialise they should each be initialised to ensure they work. whether this is in a certain aspect of code or only runs on startup of a state change, each interface, and subsequent state, should be tested. Even if the state changes are/can be simulated.
- Example GPIO toggle
	- The first test for using the hardware should be the ability to control the voltage of the pins of the microcontroller. An LED can be attached to a GPIO output for visual confirmation. Any and all GPIO interfaces used on the spacecraft should be checked and tested here if possible, to ensure switches and LEDs etc. are behaving as expected.
- Interface with local sensors
	- Before interfacing and communicating with other systems in the spacecraft, the full functionality of the OBC itself should be tested. Interfacing with onboard sensors, systems GPIO etc.
	- The introduction of possible harness issues and subsystems is a reason for the OBC to be tested on its own initially.
- Interface with Subsystems
	- 
- Collect Telemetry
	-   
- Store and Handle Telemetry
	- This includes packetising the data into a standard format. Start with the simplest most predictable telemetry packets first to test handling etc.
- Handle Telecommands
	- Start with the simplest most easy to test TCs
- Build up and finalise CONOPS
	- Now the software should have all of the key building blocks, the next step is ensure this working code only executes when expected.




