/*==============================================================================
== FILE :
==    Program to test USB communication with OBDEV drivers
================================================================================
==
== FILE NAME :
==    main.c
==
== Description :
==    This is a test program to for USB communication between the PC and an
==    Atmega8 based device. A string sent to the atmega device is echoed
==    back with ascii values incremented by unity. A byte equal to no. of chars
==		read by the muC is prefixed to the string recd. Thus the byte count recd
==		is one greater than the bytes sent to the muC.
==

==============================================================================*/

#include "DataTypes.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "usbIO.h"

S32Bit main(S32Bit argc, S8Bit **argv)
{
	U8Bit    aucBuffer[REPORT_LEN];    /* room for dummy report ID */
	S32Bit	nLen;
	U16Bit	usVal1;
	U16Bit	usVal2;
	U16Bit	usVal;
	S32Bit	j;
	S32Bit	i;
	S32Bit	Dis;


	vInitUSB();

	for ( ;; )
	{
		memset( aucBuffer, 0, REPORT_LEN );
		nLen = nReadUSB( aucBuffer );
		if ( nLen > 0 )
		{
			for ( i=4; i<19; i+=2 )
			{
					usVal2 = aucBuffer[i];
					usVal2 = ( usVal2 << 8 ) & 0xFF00;
					usVal2 |= aucBuffer[i+1];
                                        usVal1 = aucBuffer[i+16];
					usVal1 = ( usVal1 << 8 ) & 0xFF00;
					usVal1 |= aucBuffer[i+17]; 
					usVal= usVal2-usVal1;
					j=i%8;

					if (j==0)
					{
					Dis=36;
					fprintf( stderr, "%d  %d\n",Dis, usVal/10 );
					}

					else if (j==2)
					{
					Dis=42;
					fprintf( stderr, "%d  %d\n", Dis, usVal/20 );	
	      		fprintf(stderr,"\n\n\n" );
					}

					else if (j>2)
					{
						if ( j%4==0)
							Dis=24;
						else
							Dis=30; 
	      			fprintf( stderr, "%d  %d\n", Dis, usVal/1 );	
					}
			}
			fprintf(stderr,"\n\n" );
		}
		usleep(1000);
	}
	vCloseUSB();
	return 0;
}
