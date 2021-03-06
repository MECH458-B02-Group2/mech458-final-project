//------------------------------------------------------------------------------------------------------//
// GLOBAL VARIABLES ------------------------------------------------------------------------------------//
//------------------------------------------------------------------------------------------------------//

// State Machine
volatile int STATE;

// Stepper Motor
volatile int PolePosition;
volatile int CurPosition;
int const delay = 20;

// DC Motor
int const Speed = 0x50;

// Other
volatile unsigned char ADC_result;
volatile unsigned int ADC_result_flag;
volatile unsigned int Escape; // Probably WONT NEED, was for the end routine interrupt for lab 4b

//------------------------------------------------------------------------------------------------------//
// TYPE DECLARATIONS -----------------------------------------------------------------------------------//
//------------------------------------------------------------------------------------------------------//

// Linked Queue
typedef struct {
  int ferro; // Need to distinguish between aluminum and steel
	int reflect; // Need to distinguish between white and black delrin
} element;

typedef struct link{
	element e;
	struct link *next;
} link;

//------------------------------------------------------------------------------------------------------//
// STEPPER MOTOR SUBROUTINES ---------------------------------------------------------------------------//
//------------------------------------------------------------------------------------------------------//

void step_home(void);
void stepcw(int step);
void stepccw(int step);

//------------------------------------------------------------------------------------------------------//
// DC MOTOR SUBROUTINES --------------------------------------------------------------------------------//
//------------------------------------------------------------------------------------------------------//

void DC_Start(void);
void DC_Stop(void);

//------------------------------------------------------------------------------------------------------//
// TIMERS ----------------------------------------------------------------------------------------------//
//------------------------------------------------------------------------------------------------------//

void PWM(void);
void mTimer(int count);

//------------------------------------------------------------------------------------------------------//
// LINKED QUEUE SUBROUTINES ----------------------------------------------------------------------------//
//------------------------------------------------------------------------------------------------------//

void enqueue(link **h, link **t, link **nL);
void dequeue(link **h, link **t, link **deQueuedLink);