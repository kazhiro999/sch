package assignment3;

import static org.junit.Assert.*;

import org.junit.Test;
import org.junit.runner.RunWith;
import org.junit.runners.JUnit4;

//-------------------------------------------------------------------------
/**
 *  Test class for Doubly Linked List
 *
 *  @version 3.1 09/11/15 11:32:15
 *
 *  @author  Kazuhiro Tobita (18308725)
 */

@RunWith(JUnit4.class)
public class BSTTest {
  
  //TODO write more tests here.

	@Test
	public void testIsEmpty() {
		BST<Integer, Integer> bst = new BST<Integer, Integer>();
		System.out.println("\n<testIsEmpty:bst>");
		//assertTrue("Checking if an empty int bst returns empty(true)", bst.isEmpty());
		System.out.println("Confirming if an empty int bst returns empty(true) " + bst.isEmpty());
		bst.put(1,1);
		System.out.println("Confirming if 1 element int bst returns not empty(false) " + bst.isEmpty());
		bst.put(2,2);
		bst.put(3,3);
		bst.put(4,4);
		bst.put(5,5);
		bst.put(6,6);
		bst.put(7,7);
		bst.put(8,8);
		System.out.println("Confirming if 8 elements int bst returns not empty(false) " + bst.isEmpty());
		
		BST<String, Integer> alphabet = new BST<String, Integer>();
		System.out.println("\n<testIsEmpty:alphabet>");
		System.out.println("Confirming if an empty String alphabet returns empty(true) " + bst.isEmpty()); //問題あり
		alphabet.put("A",1);
		System.out.println("Confirming if 1 element String alphabet returns not empty(false) " + bst.isEmpty());
		alphabet.put("C",3);
		alphabet.put("D",4);
		alphabet.put("E",5);
		alphabet.put("F",6);
		alphabet.put("G",7);
		alphabet.put("H",8);
		System.out.println("Confirming if 8 elements String alphabet returns not empty(false) " + bst.isEmpty());
	}
	
	@Test
	public void testSize() {
		BST<Integer, Integer> bst = new BST<Integer, Integer>();
		System.out.println("\n<testSize>");
		System.out.println("Confirming size of an empty tree: " + bst.size());
		bst.put(1,1);
		System.out.println("Confirming size of 1 element tree: " + bst.size());
		bst.put(2,2);
		bst.put(3,3);
		bst.put(4,4);
		bst.put(5,5);
		bst.put(6,6);
		bst.put(7,7);
		bst.put(8,8);
		System.out.println("Confirming size of 8 element tree: " + bst.size());
		
		BST<String, Integer> alphabet = new BST<String, Integer>();
		System.out.println("\n<testSize: alphabet>");
		System.out.println("Confirming size of an empty tree: " + alphabet.size());
		alphabet.put("A",1);
		System.out.println("Confirming size of 1 element tree: " + alphabet.size());
		alphabet.put("B",2);
		alphabet.put("C",3);
		alphabet.put("D",4);
		alphabet.put("E",5);
		alphabet.put("F",6);
		alphabet.put("G",7);
		alphabet.put("H",8);
		System.out.println("Confirming size of 8 element tree: " + alphabet.size());
	}
	
	@Test
	public void testcontains() {
		BST<Integer, Integer> bst = new BST<Integer, Integer>();
		System.out.println("\n<testcontains>");
		System.out.println("Confirming if an empty int bst does not contain key 1: " + bst.contains(1));
		bst.put(1,1);
		System.out.println("Confirming if 1 element int bst contains key 1: " + bst.contains(1));
		bst.put(2,2);
		bst.put(3,3);
		bst.put(4,4);
		bst.put(5,5);
		bst.put(6,6);
		bst.put(7,7);
		bst.put(8,8);
		System.out.println("Confirming if 8 element int bst contains key 3: " + bst.contains(3));
		System.out.println("Confirming if 8 element int bst contains key 7: " + bst.contains(7));
		
		BST<String, Integer> alphabet = new BST<String, Integer>();
		System.out.println("\n<testIsEmpty:alphabet>");
		System.out.println("Confirming if an empty int bst does not contain key A: " + alphabet.contains("A"));
		alphabet.put("A",1);
		System.out.println("Confirming if 1 element int bst contains key A: " + alphabet.contains("A"));
		alphabet.put("C",3);
		alphabet.put("D",4);
		alphabet.put("E",5);
		alphabet.put("F",6);
		alphabet.put("G",7);
		alphabet.put("H",8);
		System.out.println("Confirming if 8 element int bst contains key C: " + alphabet.contains("C"));
		System.out.println("Confirming if 1 element int bst contains key G: " + alphabet.contains("G"));
	}
	
	@Test
	public void testGet() {
        BST<Integer, Integer> bst = new BST<Integer, Integer>();
		
		assertNull("Checking the get function with an empty node", bst.get(5));
		
		bst = new BST<Integer, Integer>();
		bst.put(7, 7);   //        _7_
		bst.put(8, 8);   //      /     \
						 //             8
		assertEquals("Check the ability to get a leaf node (on the right side) that is the only child node of the root.", "8", "" + bst.get(8));
		assertEquals("Check the ability to get root node with only one right child node.", "7", "" + bst.get(7));
		
		bst = new BST<Integer, Integer>();
		bst.put(7, 7);   //        _7_
		bst.put(3, 3);   //      /     \
						 //     3  
		assertEquals("Check the ability to get a leaf node (on the left side) that is the only child node of the root.", "3", "" + bst.get(3));
		assertEquals("Check the ability to get root node with only one left child node.", "7", "" + bst.get(7));
		
		bst = new BST<Integer, Integer>();
		bst.put(7, 7);   //        _7_
		bst.put(8, 8);   //      /     \
		bst.put(3, 3);   //     3       8
		assertEquals("Check the ability to get a leaf node (on the right side) that is the only node on the right side.", "8", "" + bst.get(8));
		assertEquals("Check the ability to get a leaf node (on the left side) that is the only node on the left side.", "3", "" + bst.get(3));
		assertEquals("Check the ability to get root node with two childs and that is all.", "7", "" + bst.get(7));
		
		bst = new BST<Integer, Integer>();
		bst.put(7, 7);   //        _7_
		bst.put(8, 8);   //      /     \
		bst.put(3, 3);   //    _3_      8
		bst.put(1, 1);   //  /     \
		bst.put(2, 2);   // 1       6
		bst.put(6, 6);   //  \     /
		bst.put(4, 4);   //   2   4
		bst.put(5, 5);   //  /     \
		
		assertEquals("Check the ability to get a leaf node (on the left side).", "2", "" + bst.get(2));
		assertEquals("Check the ability to get a leaf node (on the right side).", "8", "" + bst.get(8));
		assertEquals("Check the ability to get a node with a right child node.", "1", "" + bst.get(1));
		assertEquals("Check the ability to get a node with a left child node.", "6", "" + bst.get(6));
		assertEquals("Check the ability to get a node with two child nodes.", "3", "" + bst.get(3));
		assertEquals("Check the ability to get root node.", "7", "" + bst.get(7));
		assertNull("Check the ability to show an error if there is no node to check", bst.get(100));
	}
	
	@Test
	public void testPut() {
		BST<Integer, Integer> bst = new BST<Integer, Integer>();
		bst.put(7, null);
		assertNull("Check that the value put into the tree is null", bst.get(7));
		assertNull("Check that the value put into the tree is null", bst.get(null));
		
		bst = new BST<Integer, Integer>();
		bst.put(7, 7);   //        _7_
		bst.put(8, 8);   //      /     \
		bst.put(3, 3);   //    _3_      8
		bst.put(1, 1);   //  /     \
		bst.put(2, 2);   // 1       6
		bst.put(6, 6);   //  \     /
		bst.put(4, 4);   //   2   4
		bst.put(5, 5);   //  /     \
		
		assertEquals("Check the ability to get a leaf node (on the left side).", "2", "" + bst.get(2));
		assertEquals("Check the ability to get a leaf node (on the right side).", "8", "" + bst.get(8));
		assertEquals("Check the ability to get a node with a right child node.", "1", "" + bst.get(1));
		assertEquals("Check the ability to get a node with a left child node.", "6", "" + bst.get(6));
		assertEquals("Check the ability to get a node with two child nodes.", "3", "" + bst.get(3));
		assertEquals("Check the ability to get root node.", "7", "" + bst.get(7));
		assertNull("Check the ability to show an error if there is no node to check", bst.get(100));
		
		bst = new BST<Integer, Integer>();
		bst.put(7, null);
		assertNull("Putting a key with no value into a bst", bst.get(7));
		
		bst = new BST<Integer, Integer>();
		bst.put(7, 7);
		bst.put(7, 7);
		assertEquals("Putting in two of the same values and keys", Integer.valueOf(7), bst.get(7));
	}
	
	@Test
	public void testHeight() {
		BST<Integer, Integer> bst = new BST<Integer, Integer>();
		System.out.println("\n<testHeight>");
		System.out.println("Confirming an empty tree has height -1: " + bst.height());
		bst.put(1,1);
		System.out.println("Confirming 1 element tree has height 0: " + bst.height());
		bst.put(2,2);
		bst.put(3,3);
		bst.put(5,5);
		bst.put(4,4);
		System.out.println("Confirming 5 element tree has height 4: " + bst.height());
	}
	
	@Test
	public void testMedian() {
		BST<Integer, Integer> bst = new BST<Integer, Integer>();
		assertEquals("Check the median of an empty BST", "null", "" + bst.median());
		
		bst = new BST<Integer, Integer>();
		bst.put(7, 7);   //         _7_
		assertEquals("Check the median of a single node bst", Integer.valueOf(7), bst.median());
		
		bst = new BST<Integer, Integer>();
		bst.put(null, null);   //		_null_
		assertEquals("Check the median of a single node bst", null, bst.median());
		
		
		bst = new BST<Integer, Integer>();
		bst.put(7, 7);   //        _7_
		bst.put(8, 8);   //      /     \
		bst.put(3, 3);   //    _3_      8
		bst.put(1, 1);   //  /     \
		bst.put(2, 2);   // 1       6
		bst.put(6, 6);   //  \     /
		bst.put(4, 4);   //   2   4
		bst.put(5, 5);   //  /     \
						 // 		5
		assertEquals("Check the median on a BST with an 8 item tree", Integer.valueOf(4), bst.median());
		
		bst = new BST<Integer, Integer>();
		bst.put(7, 7);   //         _7_
		bst.put(5, 5);   //       / 
						 //		 5
		assertEquals("Check the median on a BST with a 2 item tree", Integer.valueOf(5), bst.median());
		
		bst = new BST<Integer, Integer>();
		bst.put(7, 7);   //         _7_
		bst.put(8, 8);   //       		\    
		bst.put(10, 10); //    	 		 8     
		bst.put(12, 12); //  		      \    
						 //    			   10  
		 			     //   				\
						 //  				 12
		assertEquals("Check the median on a BST with a single side of nodes", Integer.valueOf(8), bst.median());
	}
	
	@Test
	public void testPrintKeysInOrder() {
		BST<Integer, Integer> bst = new BST<Integer, Integer>();
		System.out.println("\n<testnPrintKeysInOrder>");
		System.out.println("Printing an empty tree: " + bst.printKeysInOrder());
		bst.put(1,1);
		System.out.println("Printing 1 element tree: " + bst.printKeysInOrder());
		bst.put(2,2);
		bst.put(3,3);
		bst.delete(3);
		bst.delete(2);
		bst.delete(1);
		System.out.println("Printing an empty tree: " + bst.printKeysInOrder());
	}

  
  /** <p>Test {@link BST#prettyPrintKeys()}.</p> */
	
    @Test
    public void testPrettyPrint() {
    	BST<Integer, Integer> bst = new BST<Integer, Integer>();
        assertEquals("Checking pretty printing of empty tree", "-null\n", bst.prettyPrintKeys());

        bst.put(7,7);
        String result1 = "-7\n"
                + " |-null\n"
                + "  -null\n";
        assertEquals("Checking pretty print of a one element tree", result1, bst.prettyPrintKeys());

        bst.put(8,8);
        bst.put(3,3);
        String result2 = "-7\n"
                + " |-3\n"
                + " | |-null\n"
                + " |  -null\n"
                + "  -8\n"
                + "   |-null\n"
                + "    -null\n";
        assertEquals("Checking pretty print of a three element tree", result2, bst.prettyPrintKeys());

        //  -7
        //   |-3
        //   | |-1
        //   | | |-null
        //   | |  -2
        //   | |   |-null
        //   | |    -null
        bst.put(1, 1);        //   |  -6
        bst.put(2, 2);        //   |   |-4
        bst.put(6, 6);        //   |   | |-null
        bst.put(4, 4);        //   |   |  -5
        bst.put(5, 5);        //   |   |   |-null
        //   |   |    -null
        //   |    -null
        //    -8
        //     |-null
        //      -null

        String result3 =
                "-7\n" +
                        " |-3\n" +
                        " | |-1\n" +
                        " | | |-null\n" +
                        " | |  -2\n" +
                        " | |   |-null\n" +
                        " | |    -null\n" +
                        " |  -6\n" +
                        " |   |-4\n" +
                        " |   | |-null\n" +
                        " |   |  -5\n" +
                        " |   |   |-null\n" +
                        " |   |    -null\n" +
                        " |    -null\n" +
                        "  -8\n" +
                        "   |-null\n" +
                        "    -null\n";
        assertEquals("Checking pretty printing of non-empty tree", result3, bst.prettyPrintKeys());


        BST<String, Integer> alphabst = new BST<String, Integer>();
        alphabst.put("G",7);
        String result4 = "-G\n"
                + " |-null\n"
                + "  -null\n";
        assertEquals("Checking pretty print of a 1 element String tree", result4, alphabst.prettyPrintKeys());
        alphabst.put("H",8);
        alphabst.put("C",3);
        String result5 = "-G\n"
                + " |-C\n"
                + " | |-null\n"
                + " |  -null\n"
                + "  -H\n"
                + "   |-null\n"
                + "    -null\n";
        assertEquals("Checking pretty print of a 3 element String tree", result5, alphabst.prettyPrintKeys());

        alphabst.put("A",1);
        alphabst.put("B",2);
        alphabst.put("F",6);
        alphabst.put("D",4);
        alphabst.put("E",5);
        String result6 =
                "-G\n" +
                        " |-C\n" +
                        " | |-A\n" +
                        " | | |-null\n" +
                        " | |  -B\n" +
                        " | |   |-null\n" +
                        " | |    -null\n" +
                        " |  -F\n" +
                        " |   |-D\n" +
                        " |   | |-null\n" +
                        " |   |  -E\n" +
                        " |   |   |-null\n" +
                        " |   |    -null\n" +
                        " |    -null\n" +
                        "  -H\n" +
                        "   |-null\n" +
                        "    -null\n";
        assertEquals("Checking pretty print of a 3 element String tree", result6, alphabst.prettyPrintKeys());
     }
  
     /** <p>Test {@link BST#delete(Comparable)}.</p> */
	
     @Test
     public void testDelete() {
         BST<Integer, Integer> bst = new BST<Integer, Integer>();
         bst.delete(1);
         assertEquals("Deleting from empty tree", "()", bst.printKeysInOrder());
         
         bst.put(7, 7);   //        _7_
         bst.put(8, 8);   //      /     \
         bst.put(3, 3);   //    _3_      8
         bst.put(1, 1);   //  /     \
         bst.put(2, 2);   // 1       6
         bst.put(6, 6);   //  \     /
         bst.put(4, 4);   //   2   4
         bst.put(5, 5);   //        \
                          //         5
         
         assertEquals("Checking order of constructed tree",
                 "(((()1(()2()))3((()4(()5()))6()))7(()8()))", bst.printKeysInOrder());
         
         bst.delete(9);
         assertEquals("Deleting non-existent key",
                 "(((()1(()2()))3((()4(()5()))6()))7(()8()))", bst.printKeysInOrder());
 
         bst.delete(8);
         assertEquals("Deleting leaf", "(((()1(()2()))3((()4(()5()))6()))7())", bst.printKeysInOrder());
 
         bst.delete(6);
         assertEquals("Deleting node with single child",
                 "(((()1(()2()))3(()4(()5())))7())", bst.printKeysInOrder());
 
         bst.delete(3);
         assertEquals("Deleting node with two children",
                 "(((()1())2(()4(()5())))7())", bst.printKeysInOrder());
         
         bst = new BST<Integer, Integer>();
         bst.put(4,4);
         bst.put(5,5);
         bst.put(6,6);
         bst.put(7,7);
         bst.put(8,8);
         bst.delete(6);
         assertEquals("Deleting node from right leaning bst", "(()4(()5(()7(()8()))))", bst.printKeysInOrder());
     }
}
