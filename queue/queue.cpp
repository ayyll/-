#include <cstdio>
#define MAX_QUEUE_LEN 10000
using namespace std;

class Queue {

	private:

		int val[MAX_QUEUE_LEN];
		int head;
		int tail;

	public:

		Queue(void) {

			head = tail = 0;
		}

		bool empty(void) {

			return head >= tail ? true : false;
		}

		int pop(void) {

			if(!empty()) {

				return val[head++];
			}
		}

		bool push(int x) {

			if(tail < MAX_QUEUE_LEN) {

				val[tail++] = x;
				return true;

			} else {

				return false;
			}
		}

		int size(void) {

			return tail - head;
		}

		int front(void) {

			if(!empty()) return val[head];
		}

		int back(void) {

			if(!empty()) return val[tail - 1];
		}

};
int main() {

	int n;

	while(~scanf("%d",&n)) {
		
		Queue q;
		for(int i = 1; i <= n; i++) {
			q.push(i);
		}

		//printf("%d\n",q.size());
		while(q.size() >= 2) {
			
			printf("%d ",q.pop());
			q.push(q.front());
			q.pop();
		}

		printf("%d\n",q.front());
	}
	return 0;
}