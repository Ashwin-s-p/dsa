 #include <iostream>
  using namespace std;

  int cqueue[5];
  int front = -1, rear = -1, n = 5;

  void insertCQ(int val) {
      if ((front == 0 && rear == n - 1) || (front == rear + 1)) {
          cout << "Queue Overflow\n";
          return;
      }
      if (front == -1) { // First element insertion
          front = 0;
          rear = 0;
      } else if (rear == n - 1 && front != 0) {
          rear = 0; // Circular increment
      } else {
      }
      cqueue[rear] = val;
  }

  void deleteCQ() {
      if (front == -1) { // Empty queue
          cout << "Queue Underflow\n";
          return;
      }
      cout << "Element deleted from queue is: " << cqueue[front] << endl;
      if (front == rear) { // Only one element
          front = -1;
          rear = -1;
      } else if (front == n - 1) {
          front = 0; // Circular increment
      } else {
          front++;
      }
  }

  void displayCQ() {
      if (front == -1) {
          cout << "Queue is empty\n";
          return;
      }
      cout << "Queue elements are:\n";
      if (front <= rear) {
          for (int i = front; i <= rear; i++) {
              cout << cqueue[i] << " ";
          }
      } else {
          for (int i = front; i < n; i++) {
              cout << cqueue[i] << " ";
          }
          for (int i = 0; i <= rear; i++) {
              cout << cqueue[i] << " ";
          }
      }
      cout << endl;
  }

  int main() {
      int ch, val;
      cout << "1) Insert\n";
      cout << "2) Delete\n";
      cout << "3) Display\n";
      cout << "4) Exit\n";
      do {
          cout << "Enter choice: ";
          cin >> ch;
          switch (ch) {
              case 1:
                  cout << "Input for insertion: ";
                  cin >> val;
                  insertCQ(val);
                  break;
              case 2:
                  deleteCQ();
                  break;
              case 3:
                  displayCQ();
                  break;
              case 4:
                  cout << "Exit\n";
                  break;
              default:
                  cout << "Incorrect choice!\n";
          }
      } while (ch != 4);
      return 0;
  }