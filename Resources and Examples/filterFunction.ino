/*The Glorious Filter Function
  Typed by Jose Catarino, but I got it from a Brian Douglass video:
  https://www.youtube.com/watch?v=LfydfvHyikM&index=40&list=PLUMWjy5jgHK1NC52DXXrriwihVrYZKqjk

  If there's a sensor value with some noise, you can use this function to get
  rid of spikes by averaging the value
*/
//include the following variables in your code
int g1 = 0;
int g2 = 0;
int g3 = 0;
int g4 = 0;
int g5 = 0;
int g = 0;

// avgFilter(variable to average)
int avgFilter (int a) {
  g5 = g4;
  g4 = g3;
  g3 = g2;
  g2 = g1;
  g1 = a;
  g = (g1 + g2 + g3 + g4 + g5) / 5;
  return g;
}
