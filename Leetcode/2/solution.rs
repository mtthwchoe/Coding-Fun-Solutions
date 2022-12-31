// Definition for singly-linked list.
// #[derive(PartialEq, Eq, Clone, Debug)]
// pub struct ListNode {
//   pub val: i32,
//   pub next: Option<Box<ListNode>>
// }
// 
// impl ListNode {
//   #[inline]
//   fn new(val: i32) -> Self {
//     ListNode {
//       next: None,
//       val
//     }
//   }
// }

impl ListNode {
  #[inline]
  fn link(behind: &mut Option<Box<ListNode>>, front: Option<Box<ListNode>>){
      if let Some(x) = behind {
        let behind = &mut **x;
        behind.next = front;
      }
  }
}

impl Solution {
    pub fn add_two_numbers(mut l1: Option<Box<ListNode>>, mut l2: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        if l1 == None {
            return(l2);
        }
        if l2 == None {
            return(l1);
        }
        let mut done1 = false;
        let mut done2 = false;
        let mut over = 0;

        //let mut head = Some(Box::new(ListNode::new(0)));
        let mut head = Some(Box::new(ListNode::new(0)));
        let mut tail = &mut head;
        loop {
            let mut p = 0;
            let mut q = 0;
            if let Some(temp) = l1 {
                p = temp.val;
                //println!("{}",p);
                l1 = temp.next;
            }
            else {
                done1 = true;
            }
            if let Some(temp) = l2 {
                q = temp.val;
                //println!("{}",q);
                l2 = temp.next;
            }
            else {
                done2 = true;
            }

            if(done1 == true && done2 == true) {
                break;
            }

            let mut current = ListNode::new(0);
            if (p + q + over >= 10 && over != 0) {
                current.val = p + q + over - 10;
            }
            else if (p + q >= 10) {
                over = over + 1;
                current.val = p + q - 10;
            }
            else {
                current.val = p + q + over;
                over = 0;
            }
            ListNode::link(tail, Some(Box::new(current)));
            if let Some(x) = tail {
                tail = &mut (*x).next;
            }
        }
        if(over != 0) {
            let te = ListNode::new(over);
            ListNode::link(tail, Some(Box::new(te)));
            if let Some(x) = tail {
                tail = &mut (*x).next;
            }
        }
        if let Some(x) = head {
            head = (*x).next;
        }
        return head;
    }
}