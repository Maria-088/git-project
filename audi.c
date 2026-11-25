
/* Auditorium Hall Booking - Phase 1
   1. Book hall: organiser name, event name, date, time slot (1-4)
   2. View all bookings
   3. Check a date and slot: show Free or Booked
   Slots: 1 = 9-11 AM, 2 = 11 AM-1 PM, 3 = 2-4 PM, 4 = 4-6 PM
*/
#include <stdio.h>
#include <string.h>

#define MAX 50

int main()
{
    char organiser[MAX][30];
    char event[MAX][30];
    char date[MAX][11];

    int slot[MAX];
    int count = 0;
    int choice = 0, i, found, s;

    char d[11];

    // Time slot names
    char *timeSlots[] = {
        "9-11 AM",
        "11 AM-1 PM",
        "2-4 PM",
        "4-6 PM"
    };

    do {
        printf("\n===== AUDITORIUM HALL BOOKING =====\n");
        printf("1. Book Hall\n");
        printf("2. View All Bookings\n");
        printf("3. Check Date and Slot\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

        case 1:

            if (count == MAX) {
                printf("Cannot book: storage full.\n");
                break;
            }

            printf("Enter organiser name: ");
            scanf(" %29[^\n]", organiser[count]);

            printf("Enter event name: ");
            scanf(" %29[^\n]", event[count]);

            printf("Enter date (DD-MM-YYYY): ");
            scanf("%10s", date[count]);

            printf("\nSlots:\n");
            printf("1. 9-11 AM\n");
            printf("2. 11 AM-1 PM\n");
            printf("3. 2-4 PM\n");
            printf("4. 4-6 PM\n");

            printf("Enter time slot (1-4): ");
            scanf("%d", &slot[count]);

            if (slot[count] < 1 || slot[count] > 4) {
                printf("Invalid slot. Booking not saved.\n");
                break;
            }

            // Check whether the slot is already booked

            found = 0;

            for (i = 0; i < count; i++) {

                if (strcmp(date[i], date[count]) == 0 &&
                    slot[i] == slot[count]) {

                    found = 1;
                    break;
                }
            }

            if (found == 1) {
                printf("Hall already booked on that date and slot.\n");
                printf("Booking not saved.\n");
                break;
            }

            count++;

            printf("Hall booked with S.No. %d\n", count);

            break;


        case 2:

            if (count == 0) {
                printf("No bookings yet.\n");
                break;
            }

            printf("\n%-6s %-20s %-20s %-11s %-15s\n",
                   "S.No.", "Organiser", "Event", "Date", "Time Slot");

            printf("--------------------------------------------------------------------------\n");

            for (i = 0; i < count; i++) {

                printf("%-6d %-20s %-20s %-11s %-15s\n",
                       i + 1,
                       organiser[i],
                       event[i],
                       date[i],
                       timeSlots[slot[i] - 1]);
            }

            break;


        case 3:

            printf("Enter date (DD-MM-YYYY): ");
            scanf("%10s", d);

            printf("Enter time slot (1-4): ");
            scanf("%d", &s);

            if (s < 1 || s > 4) {
                printf("Invalid slot. Enter 1 to 4.\n");
                break;
            }

            found = 0;

            for (i = 0; i < count; i++) {

                if (strcmp(date[i], d) == 0 &&
                    slot[i] == s) {

                    printf("BOOKED: S.No. %d, %s by %s\n",
                           i + 1, event[i], organiser[i]);

                    found = 1;
                    break;
                }
            }

            if (found == 0) {
                printf("FREE: The hall is available on %s, %s\n",
                       d, timeSlots[s - 1]);
            }

            break;


        case 4:

            printf("Exiting. Goodbye!\n");

            break;


        default:

            printf("Invalid choice. Enter 1 to 4.\n");
        }

    } while (choice != 4);

    return 0;
}
