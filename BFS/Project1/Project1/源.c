#include <stdio.h>
#include <stdlib.h>

//����ÿ�������
typedef struct status {
	int pos[2];
	int step;
	int call;
}status;
//����ڵ�
typedef struct node {
	status data;
	struct node * next;
}node;

//������У�������׺Ͷ�βָ�룩
typedef struct queue_link {
	node * front;
	node * rear;
}que;

//���
void InsertQueue(que *q, status data) {
	node * n = (node *)malloc(sizeof(node));
	n->data = data;
	n->next = NULL;//β�巨������Ԫ��ָ���
	if (q->rear == NULL) {
		q->front = n;
		q->rear = n;
	} else {
		q->rear->next = n;//��n��Ϊ��ǰ��β���ڵ���һ�ڵ�
		q->rear = n;//β��ָ��ָ��n
	}

}

//����(ɾ������Ԫ��)
void DeleteQueue(que *q) {
	node * n = q->front;
	if (q->front == NULL)//�ж϶����Ƿ�Ϊ��
		return;
	if (q->front == q->rear)//�Ƿ�ֻ��һ��Ԫ��
	{
		q->front = NULL;
		q->rear = NULL;
	} else {
		q->front = q->front->next;
		free(n);
	}

}

int bfs();

int main()
{
	int step;
	if (step = bfs()) {		
		printf("Stsp: %d\n",step);
	}
	return 0;
}
int bfs() {
	int map[5][5] = { { 0,1,0,0,0 },
					  { 0,1,0,1,0 },
					  { 0,0,0,0,0 },
					  { 0,1,1,1,0 },
					  { 0,0,0,1,0 } };
	int visitedMap[5][5] = { 0 };
	int startPoint[2] = { 0,2 };
	int endPoint[2] = { 4,4 };
	int move[4][2] = { { -1,0 },
					   { 1, 0 },
					   { 0, 1 },
					   { 0,-1 } };
	int i, xLen, yLen, moveDir;
	status sP, curP, frontSp;
	int x, y;
	int step = 0;
	xLen = 5;
	yLen = 5;
	moveDir = 4;
	sP.call = 0;
	sP.pos[0] = startPoint[0];
	sP.pos[1] = startPoint[1];
	sP.step = 0;
	que * q = (que*)malloc(sizeof(que));
	q->front = q->rear = NULL;
	InsertQueue(q, sP);
	visitedMap[startPoint[0]][startPoint[1]] = 1;
	while (q->front != NULL) {
		frontSp = q->front->data;
		for (i = 0; i < 4; i++) {
			x = frontSp.pos[0];
			y = frontSp.pos[1];
			x += move[i][0];
			y += move[i][1];
			if ((-1 < x < 5) && (-1 < y < 5) && (!visitedMap[x][y])) {
				if ((x == endPoint[0]) && (y == endPoint[1])) {
					return step++;
				}
				if (map[x][y]) {
					if (frontSp.call != 1) {
						curP.call = 1;
						curP.pos[0] = x;
						curP.pos[1] = y;
						curP.step = step + 1;
						InsertQueue(q, curP);
						visitedMap[x][y] = 1;
					}
				} else {
					curP.call = frontSp.call;
					curP.pos[0] = x;
					curP.pos[1] = y;
					curP.step = step + 1;
					InsertQueue(q, curP);
					visitedMap[x][y] = 1;
				}
			}
			
		}
		step++;
		DeleteQueue(q);
	}
	return 0;
}