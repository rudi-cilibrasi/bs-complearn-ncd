let objCount = Array.length(Animals.pathnames);
Js.log(string_of_int(objCount) ++ " objects");

let samples = Array.mapi((i, path)=>
InputDataPreprocessor.sample_of_pathname(path,i), Animals.pathnames);
let printer = Js.log;
let () = Array.iter(printer, NCD.ncdMatrix(samples));
type pathname = string;
