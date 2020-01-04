public class Switch {
    public static void main(String[] args) {
        final int MONDAY = 0, TUESDAY = 1, WEDNESDAY = 2, THURSDAY = 3, FRIDAY = 4, SATURDAY = 5,
                  SUNDAY = 6;
        int day;
        for (day = MONDAY; day <= SUNDAY; ++day) {
            switch (day) {
                case MONDAY:
                    System.out.println("it is the beginning of the week");
                case TUESDAY:
                case WEDNESDAY:
                case THURSDAY:
                case FRIDAY:
                    System.out.println("it is a weekday");
                    if (day != FRIDAY) {
                        break;
                    }
                    System.out.println("it is the end of the working week");
                    break;
                default:
                    System.out.println("yay, it's the weekend.");
            }
        }
        return;
    }
}
