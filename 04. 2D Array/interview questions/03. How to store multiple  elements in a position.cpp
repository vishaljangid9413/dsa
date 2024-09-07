// Here we find that how to store two interger values 
// in a single position or address

// Ex = We have a question, a array is given
// that is 0 < arr[i] < 99,
// and also can consist duplicate element

// now, we have to create a new array 
// and store the element with theire occurence count 
// now how can we do this,

// Example: if we have to search for 8
// and 8 is repeating itself for 4 times 
// so value = 8, occurence = 4

// so how can we store it 
// simply, arr[i] = value + occurence * 100;
//                = 9 + 4 * 100;
//      new value = 409;

// now, what if i want to get my value and its occurence from new value
// simple, 
// occurence = new_value / 100;  
//         409 / 100 == 4;
// value = new_value % 100;    
//             409 % 100 = 9

// now we have a question why did we do this (occurence * 100)
// we can also do this (value * 100) and just
// add ((value * 100) + occurence)
// its totally fine  we can do this