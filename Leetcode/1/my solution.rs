impl Solution {
    pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
        let mut x:i32 = 0;
        let mut y:i32 = 0;
        for i in 0..nums.len() {
            for j in 0..nums.len() {
                if(nums[i] + nums[j] == target && i != j) {
                    x = i as i32;
                    y = j as i32;
                }
            }
        }
        let r:Vec<i32> = vec![x,y];
        r
    }
}
