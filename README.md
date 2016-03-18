# Arduino
To use:


Thread p1;
void setup()
{
  p1.Init(500,&function); //use thread every 500ms
}
void loop()
{
  p1.Start();
}

void function(void)
{
  //TO DO
}
