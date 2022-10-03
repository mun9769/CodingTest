#include <iostream>
#include <vector>
#include <cstring>
#include <unordered_map>
using namespace std;


#define ii pair<int, int>

enum State {
	onRoad,
	onTenRoad,
	onTwentyRoad,
	onThirtyRoad,
	onLastRoad,
	done,
};
int sum = 0;


int road[30];

int tenRoad[30] = { 10,13,16,19, };

int twentyRoad[30] = { 20,22,24,};

int thirtyRoad[30] = { 30,28,27,26, };

int lastRoad[20] = { 25, 30, 35, 40 };

pair<int, State> posManager[4];

#include <stack>
class Knight {
public:
	int id = 0;
	int pos = 0;
	State state = State::onRoad;
	State prevState;
	stack<pair<int, State>> trace;

public:

	void back(){
		auto prev = trace.top();

		switch (prev.second) {
			case State::onRoad:
				sum -= road[this->pos];
				break;
			case State::onTenRoad:
				sum -= tenRoad[this->pos];
				break;
			case State::onTwentyRoad:
				sum -= twentyRoad[this->pos];
				break;
			case State::onThirtyRoad:
				sum -= thirtyRoad[this->pos];
				break;
			case State::onLastRoad:
				sum -= lastRoad[this->pos];
				break;
		}

		trace.pop();
		auto now = trace.top();

		this->pos = now.first;
		state = now.second;
		posManager[id] = now;

	}

	bool move(int dice) {
		if (state == State::done) 
			return false;

		pair<int, State> next;
		switch (state) {
			case State::onRoad:
				next = moveRoad(dice);
				break;
			case State::onTenRoad:
				next = moveTenRoad(dice);
				break;
			case State::onTwentyRoad:
				next = moveTwentyRoad(dice);
				break;
			case State::onThirtyRoad:
				next = moveThirtyRoad(dice);
				break;
			case State::onLastRoad:
				next = moveLastRoad(dice);
				break;
		}

		if(next.second != State::done)
			for (int i = 0; i < 4; i++)
				if (posManager[i] == next)
					return false;

		pos = next.first;
		state = next.second;
		trace.push(next);
		posManager[id] = next;
		
		switch (state) {
			case State::onRoad:
				sum += road[pos];
				break;
			case State::onTenRoad:
				sum += tenRoad[pos];
				break;
			case State::onTwentyRoad:
				sum += twentyRoad[pos];
				break;
			case State::onThirtyRoad:
				sum += thirtyRoad[pos];
				break;
			case State::onLastRoad:
				sum += lastRoad[pos];
				break;
		}
		return true;
	}

	pair<int,State> moveRoad(int dice) {
		int xx = this->pos + dice;
		if (xx == 5) 
			return { 0, State::onTenRoad }; 
		else if (xx == 10) 
			return { 0, State::onTwentyRoad }; 
		else if (xx == 15) 
			return { 0, State::onThirtyRoad }; 
		else if (xx == 20) 
			return { 3, State::onLastRoad }; 
		else if (xx > 20) 
			return { xx, State::done };
		
		return { xx, State::onRoad };
	}
	pair<int, State> moveTenRoad(int dice) {
		int xx = this->pos + dice;
		if (xx >= 4) 
			return { xx - 4, State::onLastRoad };
		return { xx, State::onTenRoad };
	}
	pair<int, State> moveTwentyRoad(int dice) {
		int xx = this->pos + dice;
		if (xx >= 3)
			return { xx - 3, State::onLastRoad };
		return { xx, State::onTwentyRoad };
	}
	pair<int, State> moveThirtyRoad(int dice) {
		int xx = this->pos + dice;
		if (xx >= 4) 
			return { xx - 4, State::onLastRoad };
		return { xx, State::onThirtyRoad };
	}
	pair<int, State> moveLastRoad(int dice) {
		int xx = this->pos + dice;
		if (xx >= 4) 
			return { xx, State::done };
		return { xx, State::onLastRoad };
	}

};

int dice[10];
Knight knights[4];
int result = 0;

void dfs(int index) {
	if (index == 10) {
		result = max(result, sum);
		return;
	}
	

		for (int i = 0; i < 4; i++) {

			if (knights[i].state == State::done) continue;

			if (knights[i].move(dice[index]) == false) {
				continue;
			}
			dfs(index + 1);
			knights[i].back();
		}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	for (int i = 0; i <= 20; i++)
		road[i] = i * 2;


	for (int i = 0; i < 4; i++) {
		knights[i] = Knight();
		knights[i].id = i;
		knights[i].trace.push({ 0, State::onRoad });
	}

	for (int i = 0; i < 10; i++) {
		cin >> dice[i];
	}

	knights[0].move(dice[0]);

	for (int i = 0; i < 4; i++) {
		posManager[i] = { knights[i].pos, knights[i].state };
	}

	dfs(1);

	cout << result;
}
