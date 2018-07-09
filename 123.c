// Created on Thu July 5 2018
int threshold = 1000 ;
void forward()
{
	motor(0,100);
	motor(3,100);
	msleep(100);
}
void turnRight()
{
	motor(0,100);
	motor(3,80);
	msleep(100);
}
void turnLeft()
{
	motor(0,30);
	motor(3,100);
	msleep(300);
}
void turnAround()
{
	motor(0,-100);
	motor(3,100);
	msleep(1200);
}

int main()
{
	while(1)
		{
			int LeftSensor = analog(0);
			int RightSensor = analog(1);
			if((LeftSensor < threshold) && (RightSensor < threshold))
			{
				// both see black
				printf("moving forward, sensors: %d -- %d\n", LeftSensor, RightSensor);
				forward();
			
			}
			if((LeftSensor < 500) && (RightSensor > 500))
			{
				// Left sees white, right sees black
				printf("Turn right! sensors: %d -- %d\n", LeftSensor, RightSensor);
				turnRight();
			
			}
			
			if((LeftSensor > 500) && (RightSensor < 500))
			{
				// Left sees black, right sees white
				printf("Turn left! sensors: %d -- %d\n", LeftSensor, RightSensor);
				turnLeft();
			
			}
			
			if((LeftSensor < 500) && (RightSensor < 500))
			{
				printf("U-TURN! sensors %d -- %d\n", LeftSensor, RightSensor);
				turnAround();
			}
		
			
			ao();
		}

}
 
