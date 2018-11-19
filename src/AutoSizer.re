[@bs.module "react-virtualized"] external _AutoSizer: ReasonReact.reactClass = "AutoSizer";

[@decco] type dimensions = { width: int, height: int };

let make = (children) => {
    switch (Js.Array.length(children)) {
        | 1 =>
            ReasonReact.wrapJsForReason(
                ~reactClass=_AutoSizer,
                ~props=Js.null,
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
