package solve_it;

import java.awt.geom.FlatteningPathIterator;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.Iterator;
import java.util.List;
import java.util.Set;
import java.util.Stack;
import java.util.TreeSet;

class TreeNode {
    int val;	
    TreeNode left;
    TreeNode right;
    TreeNode(int x) { val = x; }
}
class Myco implements Comparator<Integer>{
	@Override
	public int compare(Integer o1, Integer o2) {
		StringBuilder sb1=new StringBuilder();
		StringBuilder sb2=new StringBuilder();
		sb1.append(o1).append(o2);
		sb2.append(o2).append(o1);
		return sb2.toString().compareTo(sb1.toString());
	}
}
public class Solution {
	public String largestNumber(int[] nums) {
		Myco com=new Myco();
		Integer[] nums1=new Integer[nums.length];
		for(int i=0;i<nums.length;i++){
			nums1[i]=(Integer)nums[i];
		}
		Arrays.sort(nums1,com);
		StringBuilder sb=new StringBuilder();
		for(int i:nums1){
			sb.append(String.valueOf(i));
		}
		if(sb.charAt(0)=='0'&&sb.length()>1) sb.delete(0, 1);
		return sb.toString();
	}
	public static void main(String[] args) {
		int nums[]=new int[]{0,0};
		System.out.println(new Solution().largestNumber(nums));
	}
}

