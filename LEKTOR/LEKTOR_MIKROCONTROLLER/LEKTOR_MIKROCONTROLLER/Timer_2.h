 /***
 *    $$$$$$$$\$$\                                       $$$$$$\              $$\         $$\                   
 *    \__$$  __\__|                                     $$  __$$\             $$ |        $$ |                  
 *       $$ |  $$\$$$$$$\$$$$\  $$$$$$\  $$$$$$\        \__/  $$ |       $$$$$$$ |$$$$$$\ $$ |$$$$$$\ $$\   $$\ 
 *       $$ |  $$ $$  _$$  _$$\$$  __$$\$$  __$$\        $$$$$$  |      $$  __$$ $$  __$$\$$ |\____$$\$$ |  $$ |
 *       $$ |  $$ $$ / $$ / $$ $$$$$$$$ $$ |  \__|      $$  ____/       $$ /  $$ $$$$$$$$ $$ |$$$$$$$ $$ |  $$ |
 *       $$ |  $$ $$ | $$ | $$ $$   ____$$ |            $$ |            $$ |  $$ $$   ____$$ $$  __$$ $$ |  $$ |
 *       $$ |  $$ $$ | $$ | $$ \$$$$$$$\$$ |            $$$$$$$$\       \$$$$$$$ \$$$$$$$\$$ \$$$$$$$ \$$$$$$$ | 
 *       \__|  \__\__| \__| \__|\_______\__|            \________|       \_______|\_______\__|\_______|\____$$ |
 *                                                                                                    $$\   $$ |
 *                                                                                                    \$$$$$$  |
 *              Timer_2.h				                                                               \______/ 
 *				----------------------------------
 *				Driver til timer 2 delay op til max. 51 us.
 *				----------------------------------
 *				Created: 23-05-2017
 *				Author: Patrick Bjerregaard
 */						
 

#pragma once

void T2Delay_us(int delay_us); //max 15 uS delay.