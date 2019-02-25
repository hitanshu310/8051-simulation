/******************************************************************************/
/*                                                                            */
/*                   RTX51Tiny01.c:  The first RTX-51 Program                     */
/*                                                                            */
/******************************************************************************/

#include <reg51.h>
#include <rtx51tny.h>                 /* RTX-51 tiny functions & defines      */

#define T_INIT 	0
#define T_LED		1
#define T_SEG7_L	2
#define T_SEG7_H	3

int arr0[8] = { 0x0FE, 0x0FD, 0x0FB, 0x0F7, 0x0EF, 0x0DF, 0x0BF, 0x07F };
int idx0 = 7;

int arr1[10] = { 0x0C0, 0x0F9, 0x0A4, 0x0B0, 0x99, 0x92, 0x82, 0x0F8, 0x80, 0x98};
int idx1 = 9;
int idx2 = 9;

/******************************************************************************/
/*        Task 0 'init': Initialize                                           */
/******************************************************************************/
void init (void) _task_ T_INIT  {       /* program execution starts here        */
 
	P1 = 0x0FF;
	P2 = 0x0FF;
	P3 = 0x0FF;
  os_create_task (1);             /* start clock task                     */
  os_create_task (2);           /* start command task                   */
  os_create_task (3);           /* start command task                   */

  os_delete_task (0);              /* stop init task (no longer needed)    */
}


/******************************************************************************/
/*    Task 0 'led_rotate':  RTX-51 tiny starts this task with os_create_task (0)    */
/******************************************************************************/
led_rotate () _task_ T_LED  {
  while (1)  {                        /* endless loop                         */
		idx0++;
		if(idx0==8) idx0=0;
		P1 = arr0[idx0];
		os_wait (K_TMO, 50, 0);
  }
}

/******************************************************************************/
/*    Task 2 'seg7':  RTX-51 tiny starts this task with os_create_task (2)    */
/******************************************************************************/
seg7 () _task_ T_SEG7_L  {
  while (1)  {                        /* endless loop                         */
		idx1++;
		if(idx1==10) {
				idx1=0;
				os_send_signal (T_SEG7_H);
		};
		P3 = arr1[idx1];
		os_wait (K_TMO, 50, 0);
  }
}


/******************************************************************************/
/*    Task 3 'seg7':  RTX-51 tiny starts this task with os_create_task (3)    */
/******************************************************************************/
seg7_2 () _task_ T_SEG7_H  {
  while (1)  {                        /* endless loop                         */
		os_wait (K_SIG, 0, 0);
		idx2++;
		if(idx2==10) idx2=0;
		P2 = arr1[idx2];
		
  }
}
