void elevateBox()
{
  // Sweep from 0 to 40 degrees
  for (pos = 0; pos <= 40; pos += 1)
  {
    myServo.write(pos);
    delay(15); 
}
}
void lowerBox()
{
  // Sweep from 40 back to 0 degrees
  for (pos = 40; pos >= 0; pos -= 1)
  {
    myServo.write(pos);
    delay(15); 
  }
}

