let component = ReasonReact.statelessComponent("TestCell");
let make = (~cellInfo, _) => {
    ...component,
    render: _ => {
        let { Grid.key, style } = cellInfo;
        <div key style>
            (ReasonReact.string("yo"))
        </div>;
    }
};
