[@bs.module "react-virtualized"] external _AutoSizer: ReasonReact.reactClass = "AutoSizer";

[@bs.deriving abstract]
type _jsProps = {
    [@bs.optional] className: string
};

[@decco] type dimensions = { width: int, height: int };

let make = (~className=?, children) => {
    let props: _jsProps = _jsProps(~className?, ());

    switch (Js.Array.length(children)) {
        | 1 =>
            ReasonReact.wrapJsForReason(
                ~reactClass=_AutoSizer,
                ~props,
                (json) => json
                    |> dimensions_decode
                    |> ResultEx.getExn
                    |> children[0],
            );
        | _ =>
            Js.Exn.raiseError("Expected a single child; found " ++
                (children |> Js.Array.length |> string_of_int))
    };
};
