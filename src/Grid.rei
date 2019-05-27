[@decco]
type cellInfo = {
    columnIndex: int,
    isScrolling: bool,
    isVisible: bool,
    key: string,
    rowIndex: int,
    style: ReactDOMRe.style,
};

let make:
    {.
        "ref": option(ReactDOMRe.domRef), "cellRenderer": Js.Json.t => React.element,
        "columnCount": int, "columnWidth": int => int, "height": int,
        "rowCount": int, "rowHeight": int, "width": int
    } => React.element;
let makeProps:
    (   ~ref: ReactDOMRe.domRef=?, ~height: int, ~width: int, ~columnCount: int,
        ~columnWidth: int => int, ~rowCount: int, ~rowHeight: int,
        ~cellRenderer: cellInfo => React.element, unit
    ) => {.
        "ref": option(ReactDOMRe.domRef), "cellRenderer": Js.Json.t => React.element,
        "columnCount": int, "columnWidth": int => int, "height": int,
        "rowCount": int, "rowHeight": int, "width": int
    };
