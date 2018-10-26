open InputDataPreprocessor;
open Array;

let compressedSize = s=>String.length(ZLibCompressor.compressSync(s));

let singleLengths : array(sample) => array(int) = 
    map(s => compressedSize(s.content));

let doubleLengthsHalfTriangle : array(sample) => array(array(int)) = samples =>
    mapi((x, xsample) =>
      mapi((y, ysample) =>
        (x < y) ? 0 : compressedSize(xsample.content ++ ysample.content),
      samples),
    samples)

let doubleLengths : array(sample) => array(array(int)) = samples => {
    let halfTri = doubleLengthsHalfTriangle(samples);
    mapi((x, outer) => {
      mapi((y, _) => {
        let a = (x < y) ? x : y;
        let b = (x < y) ? y : x;
        get(get(halfTri, b), a);
      }, outer)
    }, halfTri)
}

