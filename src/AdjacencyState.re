type adjacencyState = {
    length: int,
    connections: array(bool)
};
let getIndexForCartesianPair : (adjacencyState, int, int) => int =
(a, x, y) =>
    x > y ? a.length*y+x : a.length*x+y;
let makeAdjacencyState : int => adjacencyState =
(ulength) => { length:ulength, connections:Array.make(ulength*ulength,false) } ;
let getConnected : (adjacencyState, int, int) => bool =
(a, x, y) => Array.get(a.connections, getIndexForCartesianPair(a, x, y));
let setConnected = (a:adjacencyState, x:int, y:int, v:bool):unit => {
    let m = (x < y) ? x : y;
    let n = (x < y) ? y : x;
    let ind = getIndexForCartesianPair(a, m, n);
    a.connections[ind] = v;
};
let rec summarize = (l: list(bool)) =>
  switch l {
  | [] => 0
  | [head, ...tail] => (head ? 1 : 0) + summarize(tail)
  };

let getNeighbors = (a:adjacencyState, x:int) =>
  Array.of_list(List.filter(i=>getConnected(a,x,i), Range.range(0, a.length)));
let getNeighborCount = (a:adjacencyState, x:int) =>
  summarize(List.map(i=>getConnected(a,x,i), Range.range(0, a.length)));



