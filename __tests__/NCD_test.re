open Jest;

let foxString = "the quick brown fox jumped over the lazy dog. " ++
  "the fancy brown fox jumped over the lazy dog. " ++
  "the quick brown fox jumped over the lazy dog.";

let rec hanoiBase = (f, t, x, n) => switch (n) {
  | 1 => f ++ t
  | n => hanoiBase(f,x,t,n-1) ++ hanoiBase(f,t,x,1) ++ hanoiBase(x,t,f,n-1)
};

let hanoi = (n:int) => hanoiBase("a", "b", "c", n);

/* it's 131070 bytes long */
let bigString = hanoi(16);

  
let samples = Array.mapi((i, path)=>
InputDataPreprocessor.sample_of_pathname(path,i), Animals.pathnames);
describe("ncd", () => {
  open Expect;
  open! Expect.Operators;
  let mat = NCD.ncdMatrix(samples);
  let v00 = int_of_float(mat[0][0]*.100.);
  let v01 = int_of_float(mat[0][1]*.100.);
  let v10 = int_of_float(mat[1][0]*.100.);
  let v11 = int_of_float(mat[1][1]*.100.);
  test("small values", () =>
      expect(v00+v11) |> toBeLessThan(20));
  test("big values", () =>
      expect(v01+v10) |> toBeGreaterThan(170));
  test("first dimension", () =>
      expect(Array.length(mat[0])) |> toBe(10));
  test("second dimension", () =>
      expect(Array.length(mat)) |> toBe(10));
  }
);

let () =
  describe(
    "nzlib",
    ExpectJs.(
      () => 
        test("#deflateRawSync", () =>
          expect(String.length(Node.Buffer.toString(NZlib.deflateRawSync(Node.Buffer.fromStringWithEncoding(foxString, `binary)))))
          |> toBe(53)
        )
      
    )
  );
let () =
  describe(
    "zlib",
    ExpectJs.(
      () => {
        test("#deflateRawSync then #inflateRawSync on foxString", () =>
          expect(Node.Buffer.toString(NZlib.inflateRawSync(NZlib.deflateRawSync(Node.Buffer.fromString(foxString)))))
          |> toBe(foxString)
        );
      }
    ),
  );

let () =
  describe(
    "zlib",
    ExpectJs.(
      () => {
        test("#deflateRawSync then #inflateRawSync on bigString", () =>
          expect(Node.Buffer.toString(NZlib.inflateRawSync(NZlib.deflateRawSync(Node.Buffer.fromString(bigString)))))
          |> toBe(bigString)
        );
      }
    ),
  );
