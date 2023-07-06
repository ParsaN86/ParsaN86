# include "motor.h"

# define motorLF 3
# define motorRF 5
# define motorLB 6
# define motorRB 9

void Motors(int l_in, int r_in) {
  if (l_in >= 0) {
    analogWrite(motorLF, l_in);
    analogWrite(motorLB, 0);
  }
  else if (l_in < 0) {
    analogWrite(motorLF, 0);
    analogWrite(motorLB, (-1) * (l_in));
  }
  if (r_in >= 0) {
    analogWrite(motorRF, r_in);
    analogWrite(motorRB, 0);
  }
  else if (r_in < 0) {
    analogWrite(motorRF, 0);
    analogWrite(motorRB, (-1) * (r_in));
  }
}
