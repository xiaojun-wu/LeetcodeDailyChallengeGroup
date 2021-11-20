class Solution {
    private int res;
    public int maxCompatibilitySum(int[][] students, int[][] mentors) {
        final int N = students.length, M = students[0].length;
        int studentScore[] = new int[N];
        int mentorScore[] = new int[N];
        this.res = 0;
        
        for(int i = 0;i < N;i++){
            int ss = 0, ms = 0;
            for(int j = 0;j < M;j++){
                ss|= (students[i][j] << j);
                ms|= (mentors[i][j] << j);
            }
            studentScore[i] = ss;
            mentorScore[i] = ms;
        }
        backtracking(studentScore,mentorScore,0,M);
        
        return res;
    }
    
    public void backtracking(int[] studentScore,int[] mentorScore,int idx,int M){
        if(idx == mentorScore.length){
            // check.
            int sum = 0;
            for(int i = 0;i < studentScore.length;i++)
                sum+= M - Integer.bitCount(studentScore[i] ^ mentorScore[i]);
            res = Math.max(res,sum);
            return;
        }
        
        for(int i = idx;i < studentScore.length;i++){
            int temp = studentScore[i];
            studentScore[i] = studentScore[idx];
            studentScore[idx] = temp;
            
            backtracking(studentScore,mentorScore,idx + 1,M);
            
            temp = studentScore[i];
            studentScore[i] = studentScore[idx];
            studentScore[idx] = temp;
        }
    }
}

// https://tinyurl.com/d6a3njpx