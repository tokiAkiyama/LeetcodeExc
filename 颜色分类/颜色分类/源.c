int main()
{
	int *zBound, *tBound, *curr;
	int nums[3] = { 0,1,0 };
	int numsSize = 3;
	int i, tmp;
	zBound = nums;
	tBound = &nums[numsSize - 1];
	curr = zBound;
	i = -1;
	while (tBound != curr) {
		i++;
		curr = &nums[i];
		if (nums[i] == 0) {
			nums[i] = *zBound;
			*zBound = 0;
			zBound++;
		}
		else if (nums[i] == 2) {
			nums[i] = *tBound;
			*tBound = 2;
			tBound--;
			i--;
			curr = &nums[i];
		}
	}
	return 0;
}