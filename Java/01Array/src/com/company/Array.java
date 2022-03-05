package com.company;

import java.util.Arrays;
import java.util.Scanner;

public class Array {
    static Scanner scn = new Scanner(System.in);
    static int cs = 0;// current size to tackle remove()

    public static void main(String[] args) {

        // double[] values = new double[10];The length need not be a constant.
        // double[] moreValues = { 32, 54, 67.5, 29, 35 };
//        String[] friends = {"Emily", "Bob", "Cindy", null};

        int[] arr = takeInput();
        display(arr);
        int deleted = removeEl(arr, 2);
        System.out.println(deleted);
    }

    public static int[] takeInput() {
        System.out.println("Size? ");
        int n = scn.nextInt();

        int[] arr = new int[n];

        for (int i = 0; i < arr.length; i++) {
            System.out.println("Enter the value for " + i + " index?");
            arr[i] = scn.nextInt();
            cs++;
        }
        return arr;
    }

    public static void display(int[] arr) {
        // Enhanced for Loop
        for (int el : arr) {
            System.out.print(el);
            // el = 0; // ERROR: this assignment does not modify array elements
        }
        System.out.println();
        System.out.println(Arrays.toString(arr));
    }

    public static int removeEl(int[] arr, int pos) {
        // unordered removal:
        int deleted = arr[pos];
        //1. swap last el with pos
        arr[pos] = arr[arr.length - 1];
        //2. decrement size
        cs--;
        for (int i = 0; i < cs; i++) {
            System.out.print(arr[i] + ", ");
        }
        //order removal:
//        for (int i = pos + 1; i < arr.length; i++)
//        {
//            arr[i - 1] = arr[i];
//        }
//        cs--;
        return deleted;
    }
}
