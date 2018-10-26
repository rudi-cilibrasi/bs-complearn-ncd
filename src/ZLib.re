[%%raw "const zlib = require('zlib');"];
[@bs.deriving abstract]
type compressionOptions = {
    level: int,
    memLevel: int,
    dictionary: string,
};
let opt = (~level=6, ~memLevel=8, ~dictionary="", ()) =>
    compressionOptions(~level=level, ~memLevel=memLevel, ~dictionary=dictionary);
let defaultOptions = opt();
[@bs.val] external jSDeflateRawSync : (string, compressionOptions) => string =
 "zlib.deflateRawSync";
let deflateRawSync : (string, option(compressionOptions)) => string = (s, ~opts=defaultOptions, ()) => jSDeflateRawSync(s, opts);
