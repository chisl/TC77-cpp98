/*
 * name:        TC77
 * description: Serially accessible digital temperature sensor particularly suited for low cost and small form-factor applications.
 * manuf:       Microchip
 * version:     0.1
 * url:         http://ww1.microchip.com/downloads/en/DeviceDoc/20092B.pdf
 * date:        2016-08-17
 * author       https://chisl.io/
 * file:        TC77.hpp
 */

#include <cinttypes>

/* Derive from class TC77_Base and implement the read and write functions! */

/* TC77: Serially accessible digital temperature sensor particularly suited for low cost and small form-factor applications. */
class TC77_Base
{
public:
	/* Pure virtual functions that need to be implemented in derived class: */
	virtual uint16_t read16(uint16_t address, uint16_t n=16) = 0;  // 16 bit read
	virtual void write(uint16_t address, uint16_t value, uint16_t n=16) = 0;  // 16 bit write
	
	
	/*****************************************************************************************************\
	 *                                                                                                   *
	 *                                            REG CONFIG                                             *
	 *                                                                                                   *
	\*****************************************************************************************************/
	
	/*
	 * REG CONFIG:
	 * Select either Shutdown, Continuous Conversion or Test modes:
	 */
	struct CONFIG
	{
		static const uint16_t __address = 0;
		
		/* Bits CONFIG: */
		struct CONFIG_
		{
			/* Mode:w */
			static const uint16_t dflt = 0b0000000000000000; // 16'b0
			static const uint16_t mask = 0b1111111111111111; // [0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15]
			static const uint16_t Shutdown = 0b1111111111111111; // 
			static const uint16_t Continuous_conversion = 0b000000000; // 
		};
	};
	
	/* Set register CONFIG */
	void setCONFIG(uint16_t value)
	{
		write(CONFIG::__address, value, 16);
	}
	
	/* Get register CONFIG */
	uint16_t getCONFIG()
	{
		return read16(CONFIG::__address, 16);
	}
	
	
	/*****************************************************************************************************\
	 *                                                                                                   *
	 *                                             REG TEMP                                              *
	 *                                                                                                   *
	\*****************************************************************************************************/
	
	/*
	 * REG TEMP:
	 * holds the temperature conversion data.
	 */
	struct TEMP
	{
		static const uint16_t __address = 2;
		
		/* Bits TEMP: */
		/* the 13 bit tws complement data from the temperature conversion  */
		struct TEMP_
		{
			static const uint16_t dflt = 0b1111111100000; // 13'b1111111100000
			static const uint16_t mask = 0b1111111111111000; // [3,4,5,6,7,8,9,10,11,12,13,14,15]
		};
		/* Bits FLAG_COMPLETE: */
		/*
		 * Bit 2 is set to a logic1 after
		 * completion of the first temperature conversion following a power-up or reset event.
		 * Bit 2 is set to a logic 0 during the time needed to complete the first
		 * temperature conversion. Therefore, the status of bit 2 can be monitored to indicate
		 * that the TC77 has completed the first temperature conversion.
		 */
		struct FLAG_COMPLETE
		{
			static const uint16_t dflt = 0b0; // 1'b0
			static const uint16_t mask = 0b0000000000000100; // [2]
		};
		/* Bits unused_0: */
		/* Bits 0 and 1 are undefined and will be tri-state outputs during a read sequence.  */
		struct unused_0
		{
			static const uint16_t dflt = 0b00; // 2'b0
			static const uint16_t mask = 0b0000000000000011; // [0,1]
		};
	};
	
	/* Set register TEMP */
	void setTEMP(uint16_t value)
	{
		write(TEMP::__address, value, 16);
	}
	
	/* Get register TEMP */
	uint16_t getTEMP()
	{
		return read16(TEMP::__address, 16);
	}
	
	
	/*****************************************************************************************************\
	 *                                                                                                   *
	 *                                             REG M_ID                                              *
	 *                                                                                                   *
	\*****************************************************************************************************/
	
	/*
	 * REG M_ID:
	 * Manufacture's identification code
	 */
	struct M_ID
	{
		static const uint16_t __address = 4;
		
		/* Bits ID: */
		struct ID
		{
			static const uint16_t dflt = 0b01010100; // 8'b1010100
			static const uint16_t mask = 0b1111111100000000; // [8,9,10,11,12,13,14,15]
		};
		/* Bits unused_0: */
		/* bits 7:2 are set to0  */
		struct unused_0
		{
			static const uint16_t dflt = 0b000000; // 6'b0
			static const uint16_t mask = 0b0000000011111100; // [2,3,4,5,6,7]
		};
		/* Bits unused_1: */
		/* Bits 1:0 are undefined and will be tri- state outputs during a read sequence  */
		struct unused_1
		{
			static const uint16_t dflt = 0b00; // 2'b0
			static const uint16_t mask = 0b0000000000000011; // [0,1]
		};
	};
	
	/* Set register M_ID */
	void setM_ID(uint16_t value)
	{
		write(M_ID::__address, value, 16);
	}
	
	/* Get register M_ID */
	uint16_t getM_ID()
	{
		return read16(M_ID::__address, 16);
	}
	
};
