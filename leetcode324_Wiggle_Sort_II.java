class Solution {
    public void wiggleSort(int[] nums) {
        int arr[] = new int[nums.length];
        for(int i = 0;i < nums.length;i++)
            arr[i] = nums[i];
        Arrays.sort(arr);
        int left = (arr.length - 1) / 2, right = arr.length - 1;
        
        for(int i = 0;i < arr.length;i++){
            nums[i] = arr[left--];
            i++;
            if(i < arr.length)
                nums[i] = arr[right--];
        }
    }
}