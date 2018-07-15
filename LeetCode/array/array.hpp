//
//  array.hpp
//  test
//
//  Created by Shulin on 2018/6/15.
//  Copyright © 2018年 Shulin. All rights reserved.
//

#ifndef array_hpp
#define array_hpp

#include <stdio.h>
#include <iostream>
#include <vector>

void display(std::vector<int>& v);
void display(std::vector<int>& v, int size);

//remove duplicates in a array
int removeDuplicates(std::vector<int>& nums);
//remove duplicates two times
int removeDuplicatesII(std::vector<int>& nums);
//plus one
std::vector<int> plusOne(std::vector<int>& digits);
//pascal's triangle
std::vector<std::vector<int> > generate(int numRows);
//pascal's triangle II: get row of Pascal's triangle using O(k) space
std::vector<int> getRow(int rowIndex);
//merge two array
void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n);
// Two sum
std::vector<int> twoSum(std::vector<int>& nums, int target);
//three sum
std::vector<std::vector<int> > threeSum(std::vector<int>& nums);
std::vector<std::vector<int> > threeSumUlti(std::vector<int>& num, int target);
//three sum closet
int threeSumClosest(std::vector<int>& nums, int target);
//4Sum
std::vector<std::vector<int> > fourSum(std::vector<int>& nums, int target);
void ksum(std::vector<int>& num, int start, int end, int target,int k, std::vector<int>& sol, std::vector<std::vector<int> >& allsol);
void twosum(std::vector<int>& num, int start, int end, int target, std::vector<int>& sol, std::vector<std::vector<int> >& allsol);
//find min in rotated sorted array
int findMin(std::vector<int>& nums);
//single element in sorted array
int singleNonDuplicate(std::vector<int>& nums);
//median of two sorted array
double findMedianSortedArrays(const std::vector<int>& A,const std::vector<int>& B);
int find_kth(std::vector<int>::const_iterator A,int m,std::vector<int>::const_iterator B,int n,int k);

std::vector<int> intersection(std::vector<int>& nums1, std::vector<int>& nums2);

#endif /* array_hpp */