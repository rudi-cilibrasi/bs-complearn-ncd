let objCount = Array.length(Animals.pathnames);
Js.log(string_of_int(objCount) ++ " objects");

let samples = Array.mapi((i, path)=>
InputDataPreprocessor.sample_of_pathname(path,i), Animals.pathnames);
let () = {
  let mat = NCD.ncdMatrix(samples);
  let v00 = mat[0][0];
  let v01 = mat[0][1];
  let v10 = mat[1][0];
  let v11 = mat[1][1];
  Js.log(v00);
  Js.log(v01);
  Js.log(v10);
  Js.log(v11);
  Js.log(Array.length(mat[0]));
}
