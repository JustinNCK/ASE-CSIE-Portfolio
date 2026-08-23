namespace Seminar11_PAW
{
    partial class Form1
    {
        /// <summary>
        ///  Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        ///  Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        ///  Required method for Designer support - do not modify
        ///  the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            dateTimePicker1 = new DateTimePicker();
            button1 = new Button();
            lblData = new Label();
            lblV1 = new Label();
            lblV2 = new Label();
            lblV3 = new Label();
            lblV4 = new Label();
            txtV1 = new TextBox();
            txtV2 = new TextBox();
            txtV3 = new TextBox();
            txtV4 = new TextBox();
            treeView1 = new TreeView();
            listBox1 = new ListBox();
            listView1 = new ListView();
            button2 = new Button();
            button3 = new Button();
            button4 = new Button();
            columnHeader1 = new ColumnHeader();
            columnHeader2 = new ColumnHeader();
            columnHeader3 = new ColumnHeader();
            columnHeader4 = new ColumnHeader();
            columnHeader5 = new ColumnHeader();
            SuspendLayout();
            // 
            // dateTimePicker1
            // 
            dateTimePicker1.CustomFormat = "yyyy-MM-dd";
            dateTimePicker1.Format = DateTimePickerFormat.Custom;
            dateTimePicker1.Location = new Point(34, 32);
            dateTimePicker1.MaxDate = new DateTime(2026, 5, 7, 0, 0, 0, 0);
            dateTimePicker1.MinDate = new DateTime(2026, 1, 1, 0, 0, 0, 0);
            dateTimePicker1.Name = "dateTimePicker1";
            dateTimePicker1.Size = new Size(453, 31);
            dateTimePicker1.TabIndex = 0;
            dateTimePicker1.Value = new DateTime(2026, 2, 5, 0, 0, 0, 0);
            // 
            // button1
            // 
            button1.Location = new Point(34, 80);
            button1.Name = "button1";
            button1.Size = new Size(453, 34);
            button1.TabIndex = 1;
            button1.Text = "Incarca cotatiile BNR";
            button1.UseVisualStyleBackColor = true;
            button1.Click += button1_Click;
            // 
            // lblData
            // 
            lblData.BorderStyle = BorderStyle.Fixed3D;
            lblData.FlatStyle = FlatStyle.System;
            lblData.Location = new Point(34, 129);
            lblData.Name = "lblData";
            lblData.Size = new Size(453, 51);
            lblData.TabIndex = 2;
            lblData.TextAlign = ContentAlignment.MiddleCenter;
            // 
            // lblV1
            // 
            lblV1.BorderStyle = BorderStyle.Fixed3D;
            lblV1.FlatStyle = FlatStyle.System;
            lblV1.Location = new Point(34, 200);
            lblV1.Name = "lblV1";
            lblV1.Size = new Size(78, 31);
            lblV1.TabIndex = 3;
            lblV1.Text = "EUR";
            lblV1.TextAlign = ContentAlignment.MiddleCenter;
            // 
            // lblV2
            // 
            lblV2.BorderStyle = BorderStyle.Fixed3D;
            lblV2.FlatStyle = FlatStyle.System;
            lblV2.Location = new Point(34, 252);
            lblV2.Name = "lblV2";
            lblV2.Size = new Size(78, 31);
            lblV2.TabIndex = 4;
            lblV2.Text = "USD";
            lblV2.TextAlign = ContentAlignment.MiddleCenter;
            // 
            // lblV3
            // 
            lblV3.BorderStyle = BorderStyle.Fixed3D;
            lblV3.FlatStyle = FlatStyle.System;
            lblV3.Location = new Point(34, 301);
            lblV3.Name = "lblV3";
            lblV3.Size = new Size(78, 31);
            lblV3.TabIndex = 5;
            lblV3.Text = "CHF";
            lblV3.TextAlign = ContentAlignment.MiddleCenter;
            // 
            // lblV4
            // 
            lblV4.BorderStyle = BorderStyle.Fixed3D;
            lblV4.FlatStyle = FlatStyle.System;
            lblV4.Location = new Point(34, 358);
            lblV4.Name = "lblV4";
            lblV4.Size = new Size(78, 31);
            lblV4.TabIndex = 6;
            lblV4.Text = "GBP";
            lblV4.TextAlign = ContentAlignment.MiddleCenter;
            // 
            // txtV1
            // 
            txtV1.Location = new Point(150, 200);
            txtV1.Name = "txtV1";
            txtV1.Size = new Size(150, 31);
            txtV1.TabIndex = 7;
            // 
            // txtV2
            // 
            txtV2.Location = new Point(150, 252);
            txtV2.Name = "txtV2";
            txtV2.Size = new Size(150, 31);
            txtV2.TabIndex = 8;
            // 
            // txtV3
            // 
            txtV3.Location = new Point(150, 301);
            txtV3.Name = "txtV3";
            txtV3.Size = new Size(150, 31);
            txtV3.TabIndex = 9;
            // 
            // txtV4
            // 
            txtV4.Location = new Point(150, 358);
            txtV4.Name = "txtV4";
            txtV4.Size = new Size(150, 31);
            txtV4.TabIndex = 10;
            // 
            // treeView1
            // 
            treeView1.Location = new Point(519, 39);
            treeView1.Name = "treeView1";
            treeView1.Size = new Size(297, 350);
            treeView1.TabIndex = 11;
            // 
            // listBox1
            // 
            listBox1.FormattingEnabled = true;
            listBox1.ItemHeight = 25;
            listBox1.Location = new Point(869, 39);
            listBox1.Name = "listBox1";
            listBox1.Size = new Size(364, 354);
            listBox1.TabIndex = 12;
            // 
            // listView1
            // 
            listView1.Columns.AddRange(new ColumnHeader[] { columnHeader1, columnHeader2, columnHeader5, columnHeader3, columnHeader4 });
            listView1.Location = new Point(34, 454);
            listView1.Name = "listView1";
            listView1.Size = new Size(1199, 345);
            listView1.TabIndex = 13;
            listView1.UseCompatibleStateImageBehavior = false;
            // 
            // button2
            // 
            button2.Location = new Point(519, 402);
            button2.Name = "button2";
            button2.Size = new Size(297, 34);
            button2.TabIndex = 14;
            button2.Text = "Sterge";
            button2.UseVisualStyleBackColor = true;
            button2.Click += button2_Click;
            // 
            // button3
            // 
            button3.Location = new Point(869, 402);
            button3.Name = "button3";
            button3.Size = new Size(364, 34);
            button3.TabIndex = 15;
            button3.Text = "Sterge";
            button3.UseVisualStyleBackColor = true;
            button3.Click += button3_Click;
            // 
            // button4
            // 
            button4.Location = new Point(34, 814);
            button4.Name = "button4";
            button4.Size = new Size(1182, 34);
            button4.TabIndex = 16;
            button4.Text = "Sterge";
            button4.UseVisualStyleBackColor = true;
            button4.Click += button4_Click;
            // 
            // columnHeader1
            // 
            columnHeader1.Text = "Data";
            columnHeader1.Width = 100;
            // 
            // columnHeader2
            // 
            columnHeader2.Text = "EUR";
            columnHeader2.Width = 100;
            // 
            // columnHeader3
            // 
            columnHeader3.DisplayIndex = 2;
            columnHeader3.Text = "CHF";
            columnHeader3.Width = 100;
            // 
            // columnHeader4
            // 
            columnHeader4.DisplayIndex = 3;
            columnHeader4.Text = "GBP";
            columnHeader4.Width = 100;
            // 
            // columnHeader5
            // 
            columnHeader5.DisplayIndex = 4;
            columnHeader5.Text = "USD";
            columnHeader5.Width = 100;
            // 
            // Form1
            // 
            AutoScaleDimensions = new SizeF(10F, 25F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(1276, 878);
            Controls.Add(button4);
            Controls.Add(button3);
            Controls.Add(button2);
            Controls.Add(listView1);
            Controls.Add(listBox1);
            Controls.Add(treeView1);
            Controls.Add(txtV4);
            Controls.Add(txtV3);
            Controls.Add(txtV2);
            Controls.Add(txtV1);
            Controls.Add(lblV4);
            Controls.Add(lblV3);
            Controls.Add(lblV2);
            Controls.Add(lblV1);
            Controls.Add(lblData);
            Controls.Add(button1);
            Controls.Add(dateTimePicker1);
            Name = "Form1";
            Text = "Curs BNR";
            Load += form_load;
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private DateTimePicker dateTimePicker1;
        private Button button1;
        private Label lblData;
        private Label lblV1;
        private Label lblV2;
        private Label lblV3;
        private Label lblV4;
        private TextBox txtV1;
        private TextBox txtV2;
        private TextBox txtV3;
        private TextBox txtV4;
        private TreeView treeView1;
        private ListBox listBox1;
        private ListView listView1;
        private Button button2;
        private Button button3;
        private Button button4;
        private ColumnHeader columnHeader1;
        private ColumnHeader columnHeader2;
        private ColumnHeader columnHeader5;
        private ColumnHeader columnHeader3;
        private ColumnHeader columnHeader4;
    }
}
