open InputDataPreprocessor;
open Array;

let ncdMatrix : array(sample) => array(array(float)) = samples => {
  let doubleLengths = CompressionEngine.doubleLengths(samples);
  let singleLengths = CompressionEngine.singleLengths(samples);
    mapi((x, xrow) => {
      mapi((y, icab) => {
        let ca =  float_of_int(get(singleLengths, x));
        let cb =  float_of_int(get(singleLengths, y));
        let cab = float_of_int(icab);
        let min = (ca < cb) ? ca : cb;
        let max = (ca < cb) ? cb : ca;
        (cab -. min) /. max;
      }, xrow)
    }, doubleLengths)
}