let cellRenderer = ({ Grid.key } as cellInfo) => <TestCell key cellInfo />;

ReactDOMRe.renderToElementWithId(
    <Grid height=500 width=500 columnCount=2 columnWidth=(_ => 100) rowCount=300
        rowHeight=20 cellRenderer />,
    "container"
);
