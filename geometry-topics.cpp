class point{
public:
	int x, y;
};

int dot(point &p, point &q, point &r){
	int x1= q.x - p.x;
	int y1 = q.y - p.y;
	int x2 = r.x - q.x;
	int y2 = r.y - q.y;
	return x1 * x2 + y1 * y2;
}

int cross(point &p, point &q, point &r){
	int x1= q.x - p.x;
	int y1 = q.y - p.y;
	int x2 = r.x - q.x;
	int y2 = r.y - q.y;
	return x1 * y2 - y1 * x2;
}

