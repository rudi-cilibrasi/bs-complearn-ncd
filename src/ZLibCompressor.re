[%%raw "const zlib = require('zlib');"];
[@bs.deriving abstract]
type compressionLevel = {
    level: int
};

let compLevel = compressionLevel(~level=9);
[@bs.val] external deflateRawSyncBase : (string, compressionLevel) => string =
 "zlib.deflateRawSync";
let compressSync : (string) => string = (s) => deflateRawSyncBase(s, compLevel);