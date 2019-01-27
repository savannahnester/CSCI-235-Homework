/*
Savannah Nester
CSCI 235 Programming Assignment 2 Question 4
You have two numbers represented by a linked list, where each node contains a single digit. The digits
are stored in reverse order, such that the 1 's digit is at the head of the list. Write a function that adds
the two numbers and returns the sum as a linked list.
*/

/*PLEASE TAKE NOTICE: This is just the function used for building the linked list!! Not the full
program!! This is the only problem submitted containing just the function and not the full program */

/*
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 class Solution {
 public:
     ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
     int carry = 0;
     ListNode* sum = new ListNode(0);
     ListNode* ref = sum;
     while(l1 != NULL || l2 != NULL) {
         if(l1 != NULL) {
             sum->val += l1->val;
             l1 = l1->next;
          }

         if(l2 != NULL) {
             sum->val += l2->val;
             l2 = l2->next;
         }

         sum->val += carry;
         if(sum->val >= 10) {
             sum->val -= 10;
             carry = 1;
         }
         else {
             carry = 0;
         }

         if(l1 != NULL || l2 != NULL) {
             sum->next = new ListNode(0);
             sum = sum->next;
         }
     }

     if(carry == 1) {
         sum->next = new ListNode(1);
     }
     return ref;
     }
